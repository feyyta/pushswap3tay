/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastrat <mcastrat@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 12:00:00 by mcastrat          #+#    #+#             */
/*   Updated: 2025/10/03 14:11:24 by mcastrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	parse_int(char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (!str[i])
		terminate("Error\n");
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			terminate("Error\n");
		result = result * 10 + (str[i] - '0');
		if ((sign == 1 && result > INT_MAX) || (sign == -1
				&& result > (long)INT_MAX + 1))
			terminate("Error\n");
		i++;
	}
	return ((int)(result * sign));
}

int	has_duplicates(t_node *head, int value)
{
	while (head)
	{
		if (head->data == value)
			return (1);
		head = head->next;
	}
	return (0);
}

void	build_stack(t_stacks *stacks, char **args)
{
	int		i;
	int		value;
	t_node	*new_node;

	i = 0;
	while (args[i])
	{
		value = parse_int(args[i]);
		if (has_duplicates(stacks->a, value))
		{
			free_list(&stacks->a);
			terminate("Error\n");
		}
		new_node = create_node(value);
		add_to_bottom(&stacks->a, new_node);
		stacks->size_a++;
		i++;
	}
	stacks->total_size = stacks->size_a;
}

int	is_stack_sorted(t_node *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->data > stack->next->data)
			return (0);
		stack = stack->next;
	}
	return (1);
}
