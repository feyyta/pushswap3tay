/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sorts.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastrat <mcastrat@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 12:00:00 by mcastrat          #+#    #+#             */
/*   Updated: 2025/10/03 14:12:33 by mcastrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static t_node	*find_min_node(t_node *stack)
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

static int	get_node_position(t_node *stack, t_node *target)
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

static void	move_min_to_top(t_stacks *stacks)
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

void	sort_two(t_stacks *stacks)
{
	if (stacks->a->data > stacks->a->next->data)
		swap_a(stacks);
}

void	sort_three(t_stacks *stacks)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	first = stacks->a;
	second = first->next;
	third = second->next;
	if (first->data > second->data && second->data < third->data
		&& first->data < third->data)
		swap_a(stacks);
	else if (first->data > second->data && second->data > third->data)
	{
		swap_a(stacks);
		reverse_rotate_a(stacks);
	}
	else if (first->data > second->data && second->data < third->data
		&& first->data > third->data)
		rotate_a(stacks);
	else if (first->data < second->data && second->data > third->data
		&& first->data < third->data)
	{
		swap_a(stacks);
		rotate_a(stacks);
	}
	else if (first->data < second->data && second->data > third->data
		&& first->data > third->data)
		reverse_rotate_a(stacks);
}

void	sort_four_five(t_stacks *stacks)
{
	while (stacks->size_a > 3)
	{
		move_min_to_top(stacks);
		push_b(stacks);
	}
	sort_three(stacks);
	while (stacks->size_b > 0)
		push_a(stacks);
}

void	simple_sort(t_stacks *stacks)
{
	if (stacks->total_size == 2)
		sort_two(stacks);
	else if (stacks->total_size == 3)
		sort_three(stacks);
	else
		sort_four_five(stacks);
}
