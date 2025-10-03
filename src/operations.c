/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastrat <mcastrat@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 12:00:00 by mcastrat          #+#    #+#             */
/*   Updated: 2025/10/03 14:12:15 by mcastrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	swap_stack(t_node **stack)
{
	t_node	*first;
	t_node	*second;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = first->prev;
	second->next = first;
	first->prev = second;
	*stack = second;
}

void	swap_a(t_stacks *stacks)
{
	swap_stack(&stacks->a);
	ft_printf("sa\n");
}
/*
void	swap_b(t_stacks *stacks)
{
	swap_stack(&stacks->b);
	ft_printf("sb\n");
}

void	swap_both(t_stacks *stacks)
{
	swap_stack(&stacks->a);
	swap_stack(&stacks->b);
	ft_printf("ss\n");
}*/