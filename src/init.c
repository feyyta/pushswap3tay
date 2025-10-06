/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastrat <mcastrat@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 12:00:00 by mcastrat          #+#    #+#             */
/*   Updated: 2025/10/06 19:42:03 by mcastrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	parse_sign(char *str, int *i)
{
	int	sign;

	sign = 1;
	while (str[*i] == ' ' || (str[*i] >= 9 && str[*i] <= 13))
		(*i)++;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			sign = -1;
		(*i)++;
	}
	return (sign);
}

static int	parse_int(char *str, char **args, t_node **stack_a)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	result = 0;
	sign = parse_sign(str, &i);
	if (!str[i])
	{
		terminate("Error\n", args, stack_a);
	}
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			terminate("Error\n", args, stack_a);
		result = result * 10 + (str[i] - '0');
		if ((sign == 1 && result > INT_MAX) || (sign == -1
				&& result > (long)INT_MAX + 1))
			terminate("Error\n", args, stack_a);
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

void	build_stack(t_stacks *stacks, char **args, int free_args)
{
	int		i;
	int		value;
	t_node	*new_node;
	char	**args_to_free;

	i = 0;
	args_to_free = NULL;
	if (free_args)
		args_to_free = args;
	while (args[i])
	{
		value = parse_int(args[i], args_to_free, &stacks->a);
		if (has_duplicates(stacks->a, value))
		{
			free_list(&stacks->a);
			terminate("Error\n", args_to_free, NULL);
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
