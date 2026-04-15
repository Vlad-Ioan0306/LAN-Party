#ifndef SOLVE2_H
#define SOLVE2_H
#include "structs.h"
#include <stdio.h>

extern int team_cnt;

queue* create_queue();

void push(stack **top, team data);

void minitask_2_1(FILE *input, FILE *output, team_node **head_teams_init, queue **q);
void minitask_2_2(FILE *input, FILE *output, queue **q, stack **st_top, team_node **head_teams);
void minitask_2_3(FILE *input, FILE *output, queue **q, stack **st_top);
void minitask_2_4(FILE *input, FILE *output, queue **q, stack **st_top, team_node **head_teams);

#endif
