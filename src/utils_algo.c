/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastrat <mcastrat@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 16:04:25 by mcastrat          #+#    #+#             */
/*   Updated: 2025/10/06 19:44:36 by mcastrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	set_rank(t_node **current, int **values, t_stacks **stacks)
{
	int	j;

	j = 0;
	while (*current)
	{
		j = 0;
		while (j < (*stacks)->total_size)
		{
			if ((*current)->data == (*values)[j])
			{
				(*current)->rank = j;
				break ;
			}
			j++;
		}
		*current = (*current)->next;
	}
}

static void	bubble_sort_array(int *arr, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

static void	cp_loop(t_node **current, int **values)
{
	int	i;

	i = 0;
	while (*current)
	{
		(*values)[i] = (*current)->data;
		*current = (*current)->next;
		i++;
	}
}

void	assign_ranks(t_stacks *stacks)
{
	t_node	*current;
	int		*values;

	values = malloc(sizeof(int) * stacks->total_size);
	if (!values)
	{
		cleanup_stacks(stacks);
		terminate("Error\n", NULL, NULL);
	}
	current = stacks->a;
	cp_loop(&current, &values);
	bubble_sort_array(values, stacks->total_size);
	stacks->sorted_arr = values;
	current = stacks->a;
	set_rank(&current, &values, &stacks);
}
