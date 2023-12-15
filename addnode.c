#include "monty.h"
/**
 * addnode - add node to stack head
 * @head: head of the stack
 * @num: new_value
 * Return: nothing
 */
void addnode(stack_t **head, int num)
{

	stack_t *new_node, *temp;

	temp = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{ printf("Error\n");
		exit(0); }
	if (temp)
		temp->prev = new_node;
	new_node->n = num;
	new_node->next = *head;
	new_node->prev = NULL;
	*head = new_node;
}



#include "monty.h"
/**
 * free_stack - frees a doubly linked list
 * @head: head of the stack
 * Return: nothing
 */
void free_stack(stack_t *head)
{
	stack_t *temp;

	temp = head;
	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}





/**
 * addqueue - add node to stack tail
 * @num: new_value
 * @head: head of the stack
 * Return: nothing
 */
void addqueue(stack_t **head, int num)
{
	stack_t *new_node, *temp;

	temp = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_node->n = num;
	new_node->next = NULL;
	if (temp)
	{
		while (temp->next)
			temp = temp->next;
	}
	if (!temp)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		temp->next = new_node;
		new_node->prev = temp;
	}
}
