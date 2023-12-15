#include "monty.h"
valu_t valu = {NULL, NULL, NULL, 0};
/**
 * main - monty code interpreter
 * @argc: number of arguments
 * @argv: argument var
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	/*valu_t valu = {NULL, NULL, NULL, 0};*/
	char *line_cont;
	FILE *file_ptr;
	size_t size = 0;
	ssize_t read_line = 1;
	stack_t *stack = NULL;
	unsigned int counter = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file_ptr = fopen(argv[1], "r");
	valu.ptr = file_ptr;
	if (!file_ptr)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (read_line > 0)
	{
		line_cont = NULL;
		read_line = getline(&line_cont, &size, file_ptr);
		valu.line_cont = line_cont;
		counter++;
		if (read_line > 0)
		{
			execute(line_cont, &stack, counter, file_ptr);
		}
		free(line_cont);
	}
	free_stack(stack);
	fclose(file_ptr);
	return (0);
}
