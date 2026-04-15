#include "solve2.h"
#include "solve1.h"
#include "structs.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// TASK 2

// QUEUE FUNCTIONS
queue *create_queue() {
  queue *q;
  q = (queue *)malloc(sizeof(queue));
  if (q == NULL) {
    return NULL;
  }
  q->front = q->rear = NULL;
  return q;
}

void add_queue(queue **q, match match) {
  queue_node *new = (queue_node *)malloc(sizeof(queue_node));
  new->match = match;
  new->next = NULL;
  if ((*q)->rear == NULL) {
    (*q)->rear = new;
  } else {
    ((*q)->rear)->next = new;
    (*q)->rear = new;
  }
  if ((*q)->front == NULL) {
    (*q)->front = (*q)->rear;
  }
}

int get_queue_elem(queue **q, match *m_out) {
  queue_node *aux;

  if (*q == NULL || (*q)->front == NULL) {
    return -1;
  }

  aux = (*q)->front;
  *m_out = aux->match;
  (*q)->front = ((*q)->front)->next;
  if ((*q)->front == NULL) {
    (*q)->rear = NULL;
  }
  free(aux);
  return 0;
}

void minitask_2_1(FILE *input, FILE *output, team_node **head_teams,
                  queue **q) {
  team_node *temp = (*head_teams);
  while (temp != NULL) {
    match new_match;
    new_match.team1 = temp->data;
    temp = temp->next;
    new_match.team2 = temp->data;
    temp = temp->next;
    add_queue(q, new_match);
    fprintf(output, "%s\n%s\n", new_match.team1.team_name,
            new_match.team2.team_name);
  }
}

void push(stack **top, team data) {
  stack *new = (stack *)malloc(sizeof(stack));
  new->winner = data;
  new->next = *top;
  *top = new;
}

int pop(stack **top, team *out) {
  if (*top == NULL) {
    return -1;
  }
  stack *temp = *top;
  *out = temp->winner;
  *top = (*top)->next;
  free(temp);
  return 0;
}

int top(stack *top, team *out) {
  if (top != NULL) {
    *out = top->winner;
    return 0;
  }
  return -1;
}

void minitask_2_2(FILE *input, FILE *output, queue **q, stack **st_top,
                  team_node **head) {
  match m;
  while (get_queue_elem(q, &m) == 0) {

    if (team_cnt >= 5 && team_cnt <= 8) {
      addAtBeginning(head, m.team1);
      addAtBeginning(head, m.team2);
    }

    char *team1_name = (char *)malloc(34 * sizeof(char));
    strcpy(team1_name, m.team1.team_name);
    char *team2_name = (char *)malloc(34 * sizeof(char));
    strcpy(team2_name, m.team2.team_name);

    int len1 = strlen(m.team1.team_name);
    strcpy(team1_name, m.team1.team_name);
    int i = 0;
    while (len1 + i < 33) {
      strcat(team1_name, " ");
      i++;
    }

    int len2 = strlen(m.team2.team_name);
    char empty[] = "";
    strcpy(team2_name, empty);
    i = 0;
    while (len2 + i < 33) {
      strcat(team2_name, " ");
      i++;
    }
    strcat(team2_name, m.team2.team_name);

    fprintf(output, "%s-%s\n", team1_name, team2_name);

    if (m.team1.points > m.team2.points) {
      for (int i = 0; i < m.team1.player_cnt; i++) {
        m.team1.players[i].points += 1;
      }
      m.team1.points += 1.0;
      push(st_top, m.team1);
      team_cnt--;
      free(team1_name);
      free(team2_name);
    } else {
      for (int i = 0; i < m.team2.player_cnt; i++) {
        m.team2.players[i].points += 1;
      }
      m.team2.points += 1.0;
      push(st_top, m.team2);
      team_cnt--;
      free(team1_name);
      free(team2_name);
    }
  }
}

void minitask_2_3(FILE *input, FILE *output, queue **q, stack **st_top) {
  team team1, team2;
  if (*st_top != NULL && (*st_top)->next == NULL) {
    pop(st_top, &team1);
    char *team1_name = (char *)malloc(35 * sizeof(char));
    strcpy(team1_name, team1.team_name);
    int len1 = strlen(team1.team_name);
    strcpy(team1_name, team1.team_name);
    int i = 0;
    while (len1 + i < 34) {
      strcat(team1_name, " ");
      i++;
    }
    fprintf(output, "%s-  %.2f\n", team1_name, team1.points);
    free(team1_name);
  } else {

    while (*st_top != NULL && (*st_top)->next != NULL) {
      pop(st_top, &team1);
      pop(st_top, &team2);
      match m;
      m.team1 = team1;
      m.team2 = team2;
      add_queue(q, m);

      char *team1_name = (char *)malloc(35 * sizeof(char));
      strcpy(team1_name, m.team1.team_name);
      char *team2_name = (char *)malloc(35 * sizeof(char));
      strcpy(team2_name, m.team2.team_name);

      int len1 = strlen(m.team1.team_name);
      strcpy(team1_name, m.team1.team_name);
      int i = 0;
      while (len1 + i < 34) {
        strcat(team1_name, " ");
        i++;
      }

      int len2 = strlen(m.team2.team_name);
      strcpy(team2_name, m.team2.team_name);
      i = 0;
      while (len2 + i < 34) {
        strcat(team2_name, " ");
        i++;
      }

      fprintf(output, "%s-  %.2f\n", team1_name, team1.points);
      fprintf(output, "%s-  %.2f\n", team2_name, team2.points);
      free(team1_name);
      free(team2_name);
    }
  }
}

void minitask_2_4(FILE *input, FILE *output, queue **q, stack **st_top,
                  team_node **head) {
  int i = 1;
  while (team_cnt > 1) {
    fprintf(output, "\n--- ROUND NO:%d\n", i);
    minitask_2_2(input, output, q, st_top, head);

    fprintf(output, "\nWINNERS OF ROUND NO:%d\n", i);
    minitask_2_3(input, output, q, st_top);

    i++;
  }
}
