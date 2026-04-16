#ifndef SOLVE_H
#define SOLVE_H
#include "solve1.h"
#include "solve2.h"
#include "solve3.h"
#include "structs.h"
#include <stdio.h>

#define FILE_ERROR 1010
#define TASK_ERROR 1020
#define ARGS_ERROR 1030
#define MALLOC_ERROR 1040
#define BUF_SIZE 128

extern int team_cnt;

int get_task(FILE *task);

void task_1(FILE *input, FILE *output, char *filepath, team_node **head);
void task_2(FILE *input, FILE *output, char *filepath, team_node **head_init,
            queue **q, stack **top, team_node **head);
void task_3(FILE *input, FILE *output, char *filepath, team_node **head_init,
            queue **q, stack **top, team_node **head, tree **root);

#endif
