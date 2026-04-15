#ifndef STRUCTS_H
#define STRUCTS_H

// STRUCTS

// TASK 1

// PLAYER
typedef struct {
  char *first_name;
  char *last_name;
  int points;
} player;

// TEAM
typedef struct {
  float points;
  int player_cnt;
  player *players;
  char *team_name;
} team;

// TEAM LINKED LIST NODE
typedef struct team_node {
  team data;
  struct team_node *next;
} team_node;

// TASK 2

// MATCH
typedef struct {
  team team1;
  team team2;
} match;

// MATCH QUEUE NODE
typedef struct elem {
  match match;
  struct elem *next;
} queue_node;

// QUEUE
typedef struct {
  queue_node *front, *rear;
} queue;

// STACK
typedef struct stack {
  team winner;
  struct stack *next;
} stack;

// TASK 3

// BINARY TREE
typedef struct t {
  team data;
  struct t *left, *right;
} tree;

#endif
