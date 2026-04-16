#ifndef SOLVE1_H
#define SOLVE1_H
#include "structs.h"
#include <stdio.h>


extern int team_cnt;
void addAtBeginning(team_node **head, team t);
void addAtEnd(team_node **head, team t);
float get_min(team_node **head);
void erase(team_node **head, float min_team_points);
void print(team_node *head, FILE* output);

void minitask_1_1(FILE *input, FILE *output, team_node **head);
void minitask_1_2(FILE *input, FILE *output, team_node **head);
void minitask_1_3(FILE *input, FILE *output, team_node **head);

#endif
