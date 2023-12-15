#include "monty.h"
/**
 * _pchar - prints the char at the top of the stack,
 * followed by a new line
 * @head: stack head
 * @num_line: line_number
 * Return: nothing
 */
void _pchar(stack_t **head, unsigned int num_line)
{
	stack_t *h;

	h = *head;
	if (!h)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", num_line);
		fclose(valu.ptr);
		free(valu.line_cont);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	if (h->n > 127 || h->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", num_line);
		fclose(valu.ptr);
		free(valu.line_cont);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", h->n);
}



#include "monty.h"
/**
 * _pstr - prints the string starting at the top of the stack,
 * followed by a new
 * @head: stack head
 * @num_line: line_number
 * Return: nothing
 */
void _pstr(stack_t **head, unsigned int num_line)
{
	stack_t *h;
	(void)num_line;

	h = *head;
	while (h)
	{
		if (h->n > 127 || h->n <= 0)
		{
			break;
		}
		printf("%c", h->n);
		h = h->next;
	}
	printf("\n");
}
