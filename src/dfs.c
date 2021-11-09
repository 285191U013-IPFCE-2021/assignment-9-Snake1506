/*
 * Search an expression using DFS.
 */

// #include <stdio.h>   /* scanf, printf */
// #include <stdlib.h>  /* abort */
// #include <stdbool.h> /* bool, true, false */
#include "../include/dfs.h"

void DFT(node *root)
{
  // Initializing a stack and pushing the root of our tree onto it
  stack *LL = NULL;
  push(&LL, root);

  // While there is still nodes in the stack, the current top node will be popped,
  // and if it has a right and/or a left child, they will be pushed onto the stack.
  // Then, the same thing is done for the new top node in the stack. This is done
  // untill there are no more nodes in the stack, which also means that the whole
  // tree is now traversed.
  while (!isEmpty(LL))
  {
    stack *popped_stack = pop(&LL);
    printf("%d\n", popped_stack->node->num);

    if (popped_stack->node->rchild != NULL)
      push(&LL, popped_stack->node->rchild);
    if (popped_stack->node->lchild != NULL)
      push(&LL, popped_stack->node->lchild);

    free(popped_stack);
  }
}

// Checking if the stack is empty (bool). Empty when it topp doesn't point to a stack.
bool isEmpty(stack *topp)
{
  return (!topp);
}

// Pushing a node onto the stack
void push(stack **topp, node *node)
{
  stack *new = malloc(sizeof(stack));
  new->node = node;
  new->next = NULL;

  stack *top = *topp;

  if (isEmpty(top))
  {
    *topp = new;
  }
  else
  {
    stack *tmp = top;
    while (tmp->next)
      tmp = tmp->next;
    tmp->next = new;
  }
}

// Removing the top node from the stack
stack *pop(stack **topp)
{
  stack *top = *topp;
  stack *tmp = top;
  if (!tmp->next) // if only 1 element
  {
    *topp = NULL;
    return tmp;
  }
  else
  {
    stack *prev = top;
    while (tmp->next) // tmp points to last stack after loop.
    {
      prev = tmp;
      tmp = tmp->next;
    }
    prev->next = NULL;
    return tmp;
  }
}

node *make_node(int num, node *left, node *right)
{
  node *new = malloc(sizeof(node));
  new->num = num;
  new->visited = false;
  new->lchild = left;
  new->rchild = right;
  return new;
}

void free_node(node *p)
{
  free(p);
}

void print_node(node *p)
{

  if (p == NULL)
    printf("NULL\n");
  else
    printf("%d", p->num);
}

void print_tree(node *p, int depth)
{
  int i;
  for (i = 0; i < depth; i = i + 1)
    printf(" ");
  printf("| ");

  if (p == NULL)
    printf("NULL\n");
  else
    printf("[%d]\n", p->num);

  if (p->lchild)
  {
    print_tree(p->lchild, depth + 1);
  }

  if (p->rchild)
    print_tree(p->rchild, depth + 1);
}

void print_stack(stack *topp)
{
  struct stack *temp = topp;

  while (temp != NULL)
  {

    print_node(temp->node);
    printf("\n");

    temp = temp->next;
  }

  printf("====\n");

  return;
}
