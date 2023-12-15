#include "monty.h"
/**
 * _mod - computes the rest of the division of the second
 * top element of the stack by the top element of the stack
 * @head: stack head
 * @num_line: line_number
 * Return: nothing
 */
void _mod(stack_t **head, unsigned int num_line)
{
	stack_t *h;
	int size = 0, temp;

	h = *head;
	while (h)
	{
		h = h->next;
		size++;
	}
	if (size < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", num_line);
		fclose(valu.ptr);
		free(valu.line_cont);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", num_line);
		fclose(valu.ptr);
		free(valu.line_cont);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = h->next->n % h->n;
	h->next->n = temp;
	*head = h->next;
	free(h);
}



#include "monty.h"
/**
 * execute - executes the opcode
 * @stack: head linked list - stack
 * @count_line: line_counter
 * @ptr: poiner to monty file
 * @line_cont: line content
 * Return: nothing
 */
int execute(char *line_cont, stack_t **stack,
		unsigned int count_line, FILE *ptr)
{
	instruction_t opst[] = {
		{"push", _push}, {"pall", _pall}, {"pint", _pint},
		{"pop", _pop}, {"swap", _swap}, {"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{"rotl", _rotl},
		{"rotr", _rotr},
		{"queue", _queue},
		{"stack", _stack},
		{NULL, NULL}
	};
	unsigned int a = 0;
	char *p;

	p = strtok(line_cont, " \n\t");
	if (p && p[0] == '#')
		return (0);
	valu.val = strtok(NULL, " \n\t");
	while (opst[a].opcode && p)
	{
		if (strcmp(p, opst[a].opcode) == 0)
		{	opst[a].f(stack, count_line);
			return (0);
		}
		a++;
	}
	if (p && opst[a].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", count_line, p);
		fclose(ptr);
		free(line_cont);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}

