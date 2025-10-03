/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastrat <mcastrat@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 12:00:00 by mcastrat          #+#    #+#             */
/*   Updated: 2025/10/03 14:11:59 by mcastrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	rotate_stack(t_node **stack)
{
	t_node	*first;
	t_node	*last;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = *stack;
	while (last->next)
		last = last->next;
	*stack = first->next;
	(*stack)->prev = NULL;
	first->next = NULL;
	first->prev = last;
	last->next = first;
}

void	rotate_a(t_stacks *stacks)
{
	rotate_stack(&stacks->a);
	ft_printf("ra\n");
}

static void	reverse_rotate_stack(t_node **stack)
{
	t_node	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = *stack;
	while (last->next)
		last = last->next;
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = *stack;
	(*stack)->prev = last;
	*stack = last;
}

void	reverse_rotate_a(t_stacks *stacks)
{
	reverse_rotate_stack(&stacks->a);
	ft_printf("rra\n");
}
/*
void	reverse_rotate_b(t_stacks *stacks)
{
	reverse_rotate_stack(&stacks->b);
	ft_printf("rrb\n");
}

void	reverse_rotate_both(t_stacks *stacks)
{
	reverse_rotate_stack(&stacks->a);
	reverse_rotate_stack(&stacks->b);
	ft_printf("rrr\n");
}

void	rotate_b(t_stacks *stacks)
{
	rotate_stack(&stacks->b);
	ft_printf("rb\n");
}

void	rotate_both(t_stacks *stacks)
{
	rotate_stack(&stacks->a);
	rotate_stack(&stacks->b);
	ft_printf("rr\n");
}*/