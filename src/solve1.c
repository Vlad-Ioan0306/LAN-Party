#include "solve1.h"
#include <float.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// TASK 1

void addAtBeginning(team_node **head, team t) {
  team_node *newteam = (team_node *)malloc(sizeof(team_node));
  newteam->data = t;
  newteam->next = *head;
  *head = newteam;
}

void addAtEnd(team_node **head, team t) {

  if (*head == NULL)
    addAtBeginning(&(*head), t);
  else {
    team_node *aux = *head;
    team_node *newteam = (team_node *)malloc(sizeof(team_node));
    newteam->data = t;
    while (aux->next != NULL) {
      aux = aux->next;
    }
    aux->next = newteam;
    newteam->next = NULL;
  }
}

float get_min(team_node **head) {
  float min = FLT_MAX;
  team_node *headcopy = *head;
  while (headcopy != NULL) {
    if (headcopy->data.points < min) {
      min = headcopy->data.points;
    }
    headcopy = headcopy->next;
  }
  return min;
}

void erase(team_node **head, float min_team_points) {
  if (*head == NULL)
    return;

  team_node *headcopy = *head;
  if (headcopy->data.points == min_team_points) {
    *head = (*head)->next;
    free(headcopy);
    team_cnt--;
    return;
  }

  team_node *prev = *head;
  headcopy = headcopy->next;
  while (headcopy != NULL) {
    if (headcopy->data.points == min_team_points) {
      prev->next = headcopy->next;
      free(headcopy);
      team_cnt--;
      return;
    } else {
      prev = headcopy;
      headcopy = headcopy->next;
    }
  }
}

void print(team_node *head, FILE *output) {
  while (head != NULL) {
    fprintf(output, "%s\n", head->data.team_name);
    head = head->next;
  }
}

// READ AND POPULATE LIST WITH DATA FROM INPUT FILE
void minitask_1_1(FILE *input, FILE *output, team_node **head) {
  fscanf(input, "%d", &team_cnt);
  for (int _team = 0; _team < team_cnt; _team++) {
    team new_team;

    new_team.team_name = (char *)malloc(128 * sizeof(char));
    fscanf(input, "%d %127[^\n]\n", &new_team.player_cnt, new_team.team_name);
    int len = strlen(new_team.team_name);
    while (len > 0 && (new_team.team_name[len - 1] == ' ' ||
                       new_team.team_name[len - 1] == '\r' ||
                       new_team.team_name[len - 1] == '\t')) {
      new_team.team_name[len - 1] = '\0';
      len--;
    }
    new_team.players = (player *)malloc(new_team.player_cnt * sizeof(player));
    float avg_points = 0;

    for (int _player = 0; _player < new_team.player_cnt; _player++) {
      new_team.players[_player].last_name = (char *)malloc(64 * sizeof(char));
      fscanf(input, "%s", new_team.players[_player].last_name);

      new_team.players[_player].first_name = (char *)malloc(64 * sizeof(char));
      fscanf(input, "%s", new_team.players[_player].first_name);

      fscanf(input, "%d", &new_team.players[_player].points);
      avg_points += new_team.players[_player].points;
    }

    new_team.points = (avg_points / new_team.player_cnt);
    addAtBeginning(&(*head), new_team);
  }
}

int find_pow_2() {
  int pow = 0;
  while (team_cnt >= 1 << (pow + 1)) {
    pow++;
  }
  return pow;
}

// ELIMINATE LOWEST SCORING TEAMS UNTIL # of TEAMS IS POWER OF 2
void minitask_1_2(FILE *input, FILE *output, team_node **head) {
  int pow = find_pow_2();
  while (team_cnt > 1 << pow) {
    float min_team_points = get_min(&(*head));
    erase(&(*head), min_team_points);
  }
}

// PRINT NEW TEAMS LIST, ONLY TEAM NAMES
void minitask_1_3(FILE *input, FILE *output, team_node **head) {
  print(*head, output);
}
