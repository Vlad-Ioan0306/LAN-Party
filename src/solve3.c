#include "solve3.h"
#include "solve2.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// TASK 3

int is_empty(tree *root) { return (root == NULL); }

// ADD TO THE LEFT IF BIGGER, ELSE ADD TO THE RIGHT
void add_tree_elem(tree **root, team t) {
  if (is_empty(*root)) {
    *root = (tree *)malloc(sizeof(tree));
    (*root)->data = t;
    (*root)->left = (*root)->right = NULL;
    return;
  }

  if (t.points > (*root)->data.points) {
    add_tree_elem(&((*root)->left), t);
  } else if (t.points < (*root)->data.points) {
    add_tree_elem(&((*root)->right), t);
  } else {
    if (strcmp(t.team_name, (*root)->data.team_name) > 0) {
      add_tree_elem(&((*root)->left), t);
    } else if (strcmp(t.team_name, (*root)->data.team_name) < 0)
      add_tree_elem(&((*root)->right), t);
  }
}

// TRAVERSE THE BINARY TREE INORDER TO OUTPUT IN DECREASING SCORE ORDER
void inorder(tree *root, FILE *output) {
  if (root) {
    inorder(root->left, output);
    fprintf(output, "%-33s -  %.2f\n", root->data.team_name, root->data.points);
    inorder(root->right, output);
  }
}

// POPULATE TREE WITH THE TOP 8 TEAMS
void minitask_3_1(FILE *input, FILE *output, team_node **head, tree **root) {
  team_node *temp = *head;
  while (temp != NULL) {
    add_tree_elem(root, temp->data);
    temp = temp->next;
  }
}

// PRINT THEM IN CORRECT ORDER
void minitask_3_2(FILE *input, FILE *output, tree **root) {
  fprintf(output, "\nTOP 8 TEAMS:\n");
  inorder((*root), output);
}
