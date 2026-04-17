#include "solve.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

  if (argc != 4) {
    printf("ERROR %d -  Not enough arguments\n", ARGS_ERROR);
    return ARGS_ERROR;
  }

  FILE *task = fopen(argv[1], "r");
  FILE *input = fopen(argv[2], "r");
  FILE *output = fopen(argv[3], "w");

  if (task == NULL || input == NULL || output == NULL) {
    printf("ERROR %d - Could not open files/wrong file path(s)\n", FILE_ERROR);
    return FILE_ERROR;
  }

  int nr_task = get_task(task);

  team_node *head_teams = NULL;
  queue *q = create_queue();
  stack *st_top = NULL;
  team_node *head_teams_fin = NULL;
  tree *root = NULL;

  switch (nr_task) {
  case 1:
    task_1(input, output, argv[1], &head_teams);
    break;
  case 2:
    task_2(input, output, argv[1], &head_teams, &q, &st_top, &head_teams_fin);
    break;
  case 3:
    task_3(input, output, argv[1], &head_teams, &q, &st_top, &head_teams_fin,
           &root);
    break;
  default:
    printf("ERROR %d - Could not find task/could not calculate task correctly\n",
           TASK_ERROR);
    break;
  }

  fclose(task);
  fclose(input);
  fclose(output);
  return 0;
}
