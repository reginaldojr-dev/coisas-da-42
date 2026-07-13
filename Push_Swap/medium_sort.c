/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgoulart <rgoulart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 14:05:48 by rgoulart          #+#    #+#             */
/*   Updated: 2026/07/12 14:06:05 by rgoulart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_chunks_to_b(t_stack_node **a, t_stack_node **b,
		int size, t_bench *bench)
{
	int	chunk_size;
	int	i;

	chunk_size = ft_sqrt(size) * 14 / 10;
	if (chunk_size < 1)
		chunk_size = 1;
	i = 0;
	while (*a)
	{
		if ((*a)->index <= i)
		{
			pb(a, b, bench);
			rb(b, bench);
			i++;
		}
		else if ((*a)->index <= i + chunk_size)
		{
			pb(a, b, bench);
			i++;
		}
		else
			ra(a, bench);
	}
}

static int	find_max_index_pos(t_stack_node *b, int max_idx)
{
	t_stack_node	*curr;
	int				pos;

	pos = 0;
	curr = b;
	while (curr->index != max_idx)
	{
		pos++;
		curr = curr->next;
	}
	return (pos);
}

static void	push_max_to_a(t_stack_node **a, t_stack_node **b, t_bench *bench)
{
	int	size;
	int	pos;
	int	max_idx;

	size = get_stack_size(*b);
	max_idx = size - 1;
	pos = find_max_index_pos(*b, max_idx);
	if (pos <= size / 2)
	{
		while ((*b)->index != max_idx)
			rb(b, bench);
	}
	else
	{
		while ((*b)->index != max_idx)
			rrb(b, bench);
	}
	pa(b, a, bench);
}

void	medium_sort(t_stack_node **a, t_stack_node **b, t_bench *bench)
{
	int	size;

	set_stack_indices(*a);
	size = get_stack_size(*a);
	if (size <= 5)
	{
		sort_small(a, b, bench);
		return ;
	}
	push_chunks_to_b(a, b, size, bench);
	while (*b)
		push_max_to_a(a, b, bench);
}
