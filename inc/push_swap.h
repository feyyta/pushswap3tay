/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastrat <mcastrat@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 12:00:00 by mcastrat          #+#    #+#             */
/*   Updated: 2025/09/29 12:00:00 by mcastrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_node
{
	int				data;
	int				rank;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_stacks
{
	t_node	*a;
	t_node	*b;
	int		size_a;
	int		size_b;
	int		*sorted_arr;
	int		total_size;
}					t_stacks;

void	terminate(char *msg);
void	free_array(char **array);
t_node	*create_node(int value);
void	add_to_bottom(t_node **head, t_node *new_node);
void	free_list(t_node **head);
int		parse_int(char *str);
int		has_duplicates(t_node *head, int value);
void	build_stack(t_stacks *stacks, char **args);
int		is_stack_sorted(t_node *stack);
void	assign_ranks(t_stacks *stacks);
void	cleanup_stacks(t_stacks *stacks);
void	execute_sorting(t_stacks *stacks);

void	swap_a(t_stacks *stacks);
void	swap_b(t_stacks *stacks);
void	swap_both(t_stacks *stacks);

void	rotate_a(t_stacks *stacks);
void	rotate_b(t_stacks *stacks);
void	rotate_both(t_stacks *stacks);

void	reverse_rotate_a(t_stacks *stacks);
void	reverse_rotate_b(t_stacks *stacks);
void	reverse_rotate_both(t_stacks *stacks);

void	push_a(t_stacks *stacks);
void	push_b(t_stacks *stacks);

void	radix_sort(t_stacks *stacks);
void	simple_sort(t_stacks *stacks);
void	sort_two(t_stacks *stacks);
void	sort_three(t_stacks *stacks);
void	sort_four_five(t_stacks *stacks);

#endif