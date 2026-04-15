#include "solve.h"
#include "solve2.h"
#include "structs.h"
#include <limits.h>
#include <stdio.h>

int team_cnt;

// GET TASK FROM INPUT FILE FUNCTION
int get_task(FILE *task) {
  int nr_task = 0;
  char c;
  while (fscanf(task, "%c", &c) == 1) {
    nr_task += ((c <= '9' && c >= '0') * (c - '0'));
  }
  return nr_task;
}

void task_1(FILE *input, FILE *output, char *filepath, team_node **head) {
  minitask_1_1(input, output, &(*head));
  minitask_1_2(input, output, &(*head));
  minitask_1_3(input, output, &(*head));
}

void task_2(FILE *input, FILE *output, char *filepath, team_node **head_init,
            queue **q, stack **top, team_node **head) {
  minitask_1_1(input, output, head_init);
  minitask_1_2(input, output, head_init);
  minitask_2_1(input, output, head_init, q);
  minitask_2_4(input, output, q, top, head);
}

void task_3(FILE *input, FILE *output, char *filepath, team_node **head_init,
            queue **q, stack **top, team_node **head, tree **root) {
  minitask_1_1(input, output, head_init);
  minitask_1_2(input, output, head_init);
  minitask_2_1(input, output, head_init, q);
  minitask_2_4(input, output, q, top, head);
  minitask_3_1(input, output, head, root);
  minitask_3_2(input, output, root);
}
