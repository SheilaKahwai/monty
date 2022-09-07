#include "monty.h"

void open_file(char *filename)
{
  FILE *fd;

  if (filename == NULL)
    exit(EXIT_FAILURE);
  fd = fopen(filename, O_RDONLY);
  if (fd < 0)
    {
      fprintf(stderr, "Error: can't open file %s\n", filename);
      exit(EXIT_FAILURE);
    }
  read_file(fd);
  fclose(fd);
}

void read_file(FILE *fd)
{
  char *line = NULL;
  size_t len = 0;
  ssize_t num_chars;
  int line_num = 1;
  while ((num_chars = getline(&line, &len, fd)) != -1)
    {
      parse_line(line, line_num);
      line_num++;
    }
  free(line);
}

void parse_line(char *line, int line_num)
{
  char *opcode;
  char *data;

  if (line)
    {
      opcode = strtok(line, "\n ");
      data = strtok(NULL, "\n ");
    }
  get_func(opcode, data, line_num);
}
