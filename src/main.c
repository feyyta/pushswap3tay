/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastrat <mcastrat@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 12:00:00 by mcastrat          #+#    #+#             */
/*   Updated: 2025/10/03 14:53:21 by mcastrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	initialize_stacks(t_stacks *stacks)
{
	stacks->a = NULL;
	stacks->b = NULL;
	stacks->size_a = 0;
	stacks->size_b = 0;
	stacks->sorted_arr = NULL;
	stacks->total_size = 0;
}

void	cleanup_stacks(t_stacks *stacks)
{
	free_list(&stacks->a);
	free_list(&stacks->b);
	if (stacks->sorted_arr)
		free(stacks->sorted_arr);
}

int	main(int argc, char **argv)
{
	t_stacks	stacks;
	char		**args;

	if (argc < 2)
		return (0);
	initialize_stacks(&stacks);
	if (argc > 2)
		build_stack(&stacks, argv + 1);
	else
	{
		args = ft_split(argv[1], ' ');
		if (!args)
			return (1);
		build_stack(&stacks, args);
		free_array(args);
		free(args);
	}
	if (!is_stack_sorted(stacks.a))
		execute_sorting(&stacks);
	cleanup_stacks(&stacks);
	return (0);
}
