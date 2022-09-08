#include "monty.h"

void open_file(char *filename)
{
  FILE *fd;

  if (filename == NULL)
    exit(EXIT_FAILURE);
  fd = fopen(filename, "r");
  if (fd == NULL)
    {
      fprintf(stderr, "Error: can't open file %s\n", filename);
      exit(EXIT_FAILURE);
    }
  read_file(fd);
  fclose(fd);
}

void read_file(FILE *fd)
{
  char line[100];
  unsigned int line_num;
  for (line_num = 1; fgets(line, 100, fd) != NULL; line_num++)
    {
      parse_line(line, line_num);
      line_num++;
    }
}

void parse_line(char *line, unsigned int line_num)
{
  char *opcode;
  char *data;

  if (line)
    {
      opcode = strtok(line, "\n ");
      if (opcode == NULL)
	return;
      data = strtok(NULL, "\n ");
    }
  get_func(opcode, data, line_num);
}
