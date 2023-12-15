#include "monty.h"
/**
 * _push - push an element to the stack
 * @head: stack head
 * @num_line: line_number
 * Return: nothing
 */
void _push(stack_t **head, unsigned int num_line)
{
	int i, j = 0,  int_check = 0;

	if (valu.val)
	{
		if (valu.val[0] == '-')
			j++;
		for (; valu.val[j] != '\0'; j++)
		{
			if (valu.val[j] > 57 || valu.val[j] < 48)
				int_check = 1; }
		if (int_check == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", num_line);
			fclose(valu.ptr);
			free(valu.line_cont);
			free_stack(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", num_line);
		fclose(valu.ptr);
		free(valu.line_cont);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	i = atoi(valu.val);
	if (valu.stack_que == 0)
		addnode(head, i);
	else
		addqueue(head, i);
}



#include "monty.h"
/**
 * _pall - prints all value on the stack
 * @head: stack head
 * @num_line: line number but not used
 * Return: nothing
 */
void _pall(stack_t **head, unsigned int num_line)
{
	stack_t *h;
	(void)num_line;

	h = *head;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
