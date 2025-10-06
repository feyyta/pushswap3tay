/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastrat <mcastrat@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 12:00:00 by mcastrat          #+#    #+#             */
/*   Updated: 2025/10/03 14:12:39 by mcastrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*preprocessing gang*/
static int	get_max_bits(int max_rank)
{
	int	bits;

	bits = 0;
	while (max_rank >> bits)
		bits++;
	return (bits);
}

void	radix_sort(t_stacks *stacks)
{
	int	max_bits;
	int	bit;
	int	size;
	int	i;

	assign_ranks(stacks);
	max_bits = get_max_bits(stacks->total_size - 1);
	bit = 0;
	while (bit < max_bits)
	{
		size = stacks->size_a;
		i = 0;
		while (i < size)
		{
			if (((stacks->a->rank >> bit) & 1) == 1)
				rotate_a(stacks);
			else
				push_b(stacks);
			i++;
		}
		while (stacks->size_b > 0)
			push_a(stacks);
		bit++;
	}
}

void	execute_sorting(t_stacks *stacks)
{
	if (stacks->total_size <= 1)
		return ;
	else if (stacks->total_size <= 5)
		simple_sort(stacks);
	else
		radix_sort(stacks);
}
