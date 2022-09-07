#include "monty.h"

void *get_func(char *op, char *data, int line_num)
{
  int i;
  int funcs = 7;

  instruction_t funcs_list[] = {
				 {"push", push_to_stack},
				 {"pall", display},
				 {"pint", print_top},
				 {"pop", remove_top},
				 {"swap", swap_nodes},
				 {"add", sum_nodes},
				 {"nop", do_nothing}
  };

  for (i = 0, i < funcs; i++)
    {
      if (funcs_list[i].opcode == op)
	call_func(funcs_list[i].f, op, data, line_num);
    }
}

void call_func(op_func f, char *op, char *data, int line_num)
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
      for (i = 0; data[i] != '\0'; i++)
	{
	  if (isdigit(val[i]) == 0)
	    {
	      fprintf(stderr, "L%d: unknown instruction %s", line_num, op);
	      exit(EXIT_FAILURE);
	    }
	}
      node = create_node(atoi(data) * flag);
      f(&node, line_num);
    }
  else
    f(&head, line_num);
}

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
