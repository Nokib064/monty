#include "monty.h"
/**
 *_nop- do nothing
 *@head: stack head
 *@num_line: line_number
 *Return: nothing
 */
void _nop(stack_t **head, unsigned int num_line)
{
	(void) num_line;
	(void) head;
}


#include "monty.h"
/**
 * _swap - swaps the top two elements of the stack.
 * @head: stack head
 * @num_line: line_number
 * Return: nothing
 */
void _swap(stack_t **head, unsigned int num_line)
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
		fprintf(stderr, "L%d: can't swap, stack too short\n", num_line);
		fclose(valu.ptr);
		free(valu.line_cont);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	temp = h->n;
	h->n = h->next->n;
	h->next->n = temp;
}

