#include "monty.h"

/**
 * push_to_stack - adds a node to top of stack
 * @new_node: created node to add to stack
 * @line_num: line number of opcode
 */

void push_to_stack(stack_t **new_node, unsigned int line_num)
{
stack_t *temp;
(void) line_num;
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

/**
 * display - displays the contents of the stack
 * @stack: double pointer to top of stack
 * @line_num: line number of opcode
 */

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
