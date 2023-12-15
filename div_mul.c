#include "monty.h"
/**
 * _mul - multiplies the top two elements of the stack.
 * @head: stack head
 * @num_line: line_number
 * Return: nothing
 */
void _mul(stack_t **head, unsigned int num_line)
{
	stack_t *h;
	int size = 0, temp;

	h = *head;
	while (h)
	{
		h = h->next;
		size++;
		if (size < 2)
		{
			fprintf(stderr, "L%d: can't mul, stack too short\n", num_line);
			fclose(valu.ptr);
			free(valu.line_cont);
			free_stack(*head);
			exit(EXIT_FAILURE);
		}
		h = *head;
		temp = h->next->n * h->n;
		h->next->n = temp;
		*head = h->next;
		free(h);
	}
}



#include "monty.h"
/**
 * _div - divides the top two elements of the stack.
 * @head: stack head
 * @num_line: line_number
 * Return: nothing
 */
void _div(stack_t **head, unsigned int num_line)
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
		fprintf(stderr, "L%d: can't div, stack too short\n", num_line);
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
	temp = h->next->n / h->n;
	h->next->n = temp;
	*head = h->next;
	free(h);
}
