/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastrat <mcastrat@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 12:00:00 by mcastrat          #+#    #+#             */
/*   Updated: 2025/10/03 14:12:50 by mcastrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	terminate(char *msg, char **args, t_node **stack_a)
{
	if (args)
	{
		free_array(args);
		free(args);
	}
	if (stack_a)
		free_list(stack_a);
	write(2, msg, 6);
	exit(1);
}

void	free_array(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
}

t_node	*create_node(int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		terminate("Error\n", NULL, NULL);
	new_node->data = value;
	new_node->rank = 0;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

void	add_to_bottom(t_node **head, t_node *new_node)
{
	t_node	*current;

	if (!*head)
	{
		*head = new_node;
		return ;
	}
	current = *head;
	while (current->next)
		current = current->next;
	current->next = new_node;
	new_node->prev = current;
}

void	free_list(t_node **head)
{
	t_node	*current;
	t_node	*next;

	if (!head || !*head)
		return ;
	current = *head;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*head = NULL;
}
