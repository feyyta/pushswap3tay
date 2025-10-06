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

void	sort_two(t_stacks *stacks)
{
	if (stacks->a->data > stacks->a->next->data)
		swap_a(stacks);
}

void	sort_three(t_stacks *stacks, t_node *first, t_node *second,
	t_node *third)
{
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
	t_node	first;
	t_node	second;
	t_node	third;

	while (stacks->size_a > 3)
	{
		move_min_to_top(stacks);
		push_b(stacks);
	}
	sort_three(stacks, &first, &second, &third);
	while (stacks->size_b > 0)
		push_a(stacks);
}

void	simple_sort(t_stacks *stacks)
{
	t_node	first;
	t_node	second;
	t_node	third;

	if (stacks->total_size == 2)
		sort_two(stacks);
	else if (stacks->total_size == 3)
		sort_three(stacks, &first, &second, &third);
	else
		sort_four_five(stacks);
}
