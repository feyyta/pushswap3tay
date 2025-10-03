/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastrat <mcastrat@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 12:00:00 by mcastrat          #+#    #+#             */
/*   Updated: 2025/10/03 14:12:23 by mcastrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	push_a(t_stacks *stacks)
{
	t_node	*node_to_push;

	if (!stacks->b)
		return ;
	node_to_push = stacks->b;
	stacks->b = stacks->b->next;
	if (stacks->b)
		stacks->b->prev = NULL;
	node_to_push->next = stacks->a;
	node_to_push->prev = NULL;
	if (stacks->a)
		stacks->a->prev = node_to_push;
	stacks->a = node_to_push;
	stacks->size_a++;
	stacks->size_b--;
	ft_printf("pa\n");
}

void	push_b(t_stacks *stacks)
{
	t_node	*node_to_push;

	if (!stacks->a)
		return ;
	node_to_push = stacks->a;
	stacks->a = stacks->a->next;
	if (stacks->a)
		stacks->a->prev = NULL;
	node_to_push->next = stacks->b;
	node_to_push->prev = NULL;
	if (stacks->b)
		stacks->b->prev = node_to_push;
	stacks->b = node_to_push;
	stacks->size_a--;
	stacks->size_b++;
	ft_printf("pb\n");
}
