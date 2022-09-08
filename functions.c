#include "monty.h"

void push_to_stack(stack_t **new_node, __attribute__((unused))unsigned int line_num)
{
  stack_t *temp;

  if (new_node == NULL || *new_node == NULL)
    exit(EXIT_FAILURE);
  if (head == NULL)
    {
      head = *new_node;
      return;
    }
  temp = head;
  head = *new_node;
  head->next = temp;
  temp->prev = head;
}

void display(stack_t **stack, unsigned int line_num)
{
  stack_t *temp;

  (void) line_num;
  if (stack == NULL)
    exit(EXIT_FAILURE);
  temp = *stack;
  while (temp != NULL)
    {
      printf("%d\n", temp->n);
      temp = temp->next;
    }
}
