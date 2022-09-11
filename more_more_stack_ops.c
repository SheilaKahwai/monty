#include "monty.h"

/**
 * pstr_nodes - prints the string starting at the top of the stack
 * @stack: double pointer to top of stack
 * @line_num: line number of opcode
 */

void pstr_nodes(stack_t **stack, unsigned int line_num)
{
(void) line_num;
stack_t *temp;

temp = *stack;
if (stack == NULL || *stack == NULL)
{
printf("\n");
return;
}
while(temp != NULL)
{
if (*stack->n > 122 || *stack->n <= 0)
break;
printf("%c", temp->n);
temp = temp->next;
}
printf("\n");
}
