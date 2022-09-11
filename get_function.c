#include "monty.h"

/**
 * get_func - finds the function connected to the opcode
 * @op: opcode
 * @data: data after opcode
 * @line_num: line number of the string containing opcode
 * @format: format specifier
 */
void get_func(char *op, char *data, unsigned int line_num, int format)
{
int i, flag, count;
instruction_t funcs_list[] = {
{"push", push_to_stack},
{"pall", display},
{"pint", print_top},
{"pop", remove_top},
{"swap", swap_nodes},
{"add", sum_nodes},
{"nop", do_nothing},
{"sub", sub_nodes},
{"div", div_nodes},
{"mul", mul_nodes},
{"mod", mod_nodes},
{"pchar", pchar_node},
{"pstr", pstr_nodes},
{"rotl", rotate_top}
};
count = 14;
if (op[0] == '#')
return;
for (flag = 1, i = 0; i < count; i++)
{
if (strcmp(op, funcs_list[i].opcode) == 0)
{
call_func(funcs_list[i].f, op, data, line_num, format);
flag = 0;
}
}
if (flag == 1)
{
fprintf(stderr, "L%d: unknown instruction %s\n", line_num, op);
exit(EXIT_FAILURE);
}
}

/**
 * call_func - calls the opcode's function
 * @f: opcode function
 * @op: opcode
 * @data: data after opcode
 * @line_num: line number of string containing opcode
 * @fmt: format specifier
 */
void call_func(op_func f, char *op, char *data, unsigned int line_num, int fmt)
{
stack_t *node;
int flag;
int i;

flag = 1;
if (strcmp(op, "push") == 0)
{
if (data != NULL && data[0] == '-')
{
data = data + 1;
flag = -1;
}
if (data == NULL)
{
fprintf(stderr, "L%d: usage: push integer\n", line_num);
exit(EXIT_FAILURE);
}
for (i = 0; data[i] != '\0'; i++)
{
if (isdigit(data[i]) == 0)
{
fprintf(stderr, "L%d: usage: push integer\n", line_num);
exit(EXIT_FAILURE);
}
}
node = create_node(atoi(data) * flag);
if (fmt == 0)
f(&node, line_num);
}
else
f(&head, line_num);
}

/**
 *create_node - creates a node to add to stack
 * @n: data to be added to node
 * Return: created node
 */

stack_t *create_node(int n)
{
stack_t *node;
node = malloc(sizeof(stack_t));
if (node == NULL)
{
fprintf(stderr, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}
node->next = NULL;
node->prev = NULL;
node->n = n;

return (node);
}

/**
 * free_nodes - frees memory dynamically allocated
 */
void free_nodes(void)
{
stack_t *temp;

if (head == NULL)
return;

while (head != NULL)
{
temp = head;
head = head->next;
free(temp);
}
}
