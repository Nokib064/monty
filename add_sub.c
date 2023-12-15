#include "monty.h"
/**
 * _add - adds the top two elements of the stack.
 * @head: stack head
 * @num_line: line_number
 * Return: no return
 */
void _add(stack_t **head, unsigned int num_line)
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
		fprintf(stderr, "L%d: can't add, stack too short\n", num_line);
		fclose(valu.ptr);
		free(valu.line_cont);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	temp = h->n + h->next->n;
	h->next->n = temp;
	*head = h->next;
	free(h);
}




#include "monty.h"
/**
 *_sub- subtracts top element of the stack from second top element of  stack.
 *@head: stack head
 *@num_line: line_number
 *Return: nothing
 */
void _sub(stack_t **head, unsigned int num_line)
{
	stack_t *temp;
	int t, size;

	temp = *head;
	for (size = 0; temp != NULL; size++)
		temp = temp->next;
	if (size < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", num_line);
		fclose(valu.ptr);
		free(valu.line_cont);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	t = temp->next->n - temp->n;
	temp->next->n = t;
	*head = temp->next;
	free(temp);
}
