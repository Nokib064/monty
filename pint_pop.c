#include "monty.h"
/**
 * _pint - prints value at the top of stack
 * @head: stack head
 * @num_line: line_number
 * Return: nothing
 */
void _pint(stack_t **head, unsigned int num_line)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", num_line);
		fclose(valu.ptr);
		free(valu.line_cont);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}


#include "monty.h"
/**
 * _pop - remove top element of stack
 * @head: stack head
 * @num_line: line_number
 * Return: nothing
 */
void _pop(stack_t **head, unsigned int num_line)
{
	stack_t *h;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", num_line);
		fclose(valu.ptr);
		free(valu.line_cont);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	*head = h->next;
	free(h);
}
