#include <stdbool.h> /* bool, true, false */
#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
  int num;
  bool visited;
  struct node *lchild;
  struct node *rchild;
} node;

node *make_node(int num, node *left, node *right);

// void free_node (node * p);

void print_node(node *p);

void print_tree(node *p, int depth);

void DFT(node *root);

typedef struct stack
{
  struct node *node;
  struct stack *next;
} stack;

void push(stack **topp, node *node);

bool isEmpty(stack *topp);

node *top(stack *topp);

stack *pop(stack **topp);

void print_stack(stack *topp);
