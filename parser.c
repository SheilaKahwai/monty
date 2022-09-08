#include "monty.h"

/**
 * open_file - opens a file
 * @filename: name of file to open
 */

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

/**
 * read_file - reads a file
 * @fd: pointer to file descriptor of open file
 */

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

/**
 * parse_line - parses line read and divides it into opcode and data
 * @line:  string to parse
 * @line_num: line number of the string to be parsed
 */

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
