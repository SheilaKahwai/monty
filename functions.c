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

/**
 * print_top - prints the top node of the stack
 * @stack: double pointer to top of stack
 * @line_num: line number of the opcode
 */

void print_top(stack_t **stack, unsigned int line_num)
{
if (stack == NULL || *stack == NULL)
{
fprintf(stderr, "L%d: can't pint, stack empty\n", line_num);
exit(EXIT_FAILURE);
}
printf("%d\n", (*stack)->n);
}

/**
 * remove_top - removes top node
 * @stack: double pointer to top of stack
 * @line_num: line number of opcode
 */

void remove_top(stack_t **stack, unsigned int line_num)
{
stack_t *temp;
if (stack == NULL || *stack == NULL)
{
fprintf(stderr, "L%d: can't pop an empty stack\n", line_num);
exit(EXIT_FAILURE);
}
temp = *stack;
*stack = temp->next;
if (*stack != NULL)
(*stack)->prev = NULL;
free(temp);
}

/**
 * nop - does nothing
 * @stack: double pointer to top of stack
 * @line_num: line number of opcode
 */
void do_nothing(stack_t **stack, unsigned int line_num)
{
(void)stack;
(void)line_num;
}

/**
 * swap_nodes - swaps the top two stack nodes
 * @stack: double pointer to top of stack
 * @line_num: line number of opcode
 */

void swap_nodes(stack_t **stack, unsigned int line_num)
{
stack_t *temp;
if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
{
fprintf(stderr, "L%d: can't swap, stack too short", line_num);
exit(EXIT_FAILURE);
}
temp = (*stack)->next;
(*stack)->next = temp->next;
if (temp->next != NULL)
temp->next->prev = *stack;
temp->next = *stack;
(*stack)->prev = temp;
temp->prev = NULL;
*stack = temp;
}
