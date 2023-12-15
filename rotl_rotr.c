#include "monty.h"
/**
 * _rotl- rotates the stack to the top
 * @head: stack head
 * @num_line: line_number
 * Return: nothing
 */
void _rotl(stack_t **head,  __attribute__((unused)) unsigned int num_line)
{
	stack_t *tmp = *head, *temp;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	temp = (*head)->next;
	temp->prev = NULL;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = tmp;
	(*head) = temp;
}



#include "monty.h"
/**
 * _rotr- rotates the stack to the bottom
 * @head: stack head
 * @num_line: line_number
 * Return: nothing
 */
void _rotr(stack_t **head, __attribute__((unused)) unsigned int num_line)
{
	stack_t *temp;

	temp = *head;
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	while (temp->next)
	{
		temp = temp->next;
	}
	temp->next = *head;
	temp->prev->next = NULL;
	temp->prev = NULL;
	(*head)->prev = temp;
	(*head) = temp;
}

