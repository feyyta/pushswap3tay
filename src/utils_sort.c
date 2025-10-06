/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utlis_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastrat <mcastrat@student.s19.be>         #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-06 17:36:13 by mcastrat          #+#    #+#             */
/*   Updated: 2025-10-06 17:36:13 by mcastrat         ###   ########i         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_node	*find_min_node(t_node *stack)
{
	t_node	*min_node;
	int		min_value;

	if (!stack)
		return (NULL);
	min_node = stack;
	min_value = stack->data;
	while (stack)
	{
		if (stack->data < min_value)
		{
			min_value = stack->data;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}

int	get_node_position(t_node *stack, t_node *target)
{
	int	i;

	i = 0;
	while (stack && stack != target)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

void	move_min_to_top(t_stacks *stacks)
{
	t_node	*min_node;
	int		position;
	int		middle;

	min_node = find_min_node(stacks->a);
	position = get_node_position(stacks->a, min_node);
	middle = stacks->size_a / 2;
	if (position <= middle)
	{
		while (stacks->a != min_node)
			rotate_a(stacks);
	}
	else
	{
		while (stacks->a != min_node)
			reverse_rotate_a(stacks);
	}
}
