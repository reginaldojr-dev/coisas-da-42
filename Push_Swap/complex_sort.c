/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgoulart <rgoulart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 14:03:47 by rgoulart          #+#    #+#             */
/*   Updated: 2026/07/12 14:03:55 by rgoulart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include "push_swap.h"

static int	get_max_bits(int size)
{
	int	bits;

	bits = 0;
	while ((size - 1) >> bits)
		bits++;
	return (bits);
}

static void	sort_bit(t_stack_node **a, t_stack_node **b,
		t_bench *bench, int bit)
{
	int	size;
	int	i;

	size = get_stack_size(*a);
	i = 0;
	while (i < size)
	{
		if (((*a)->index >> bit) & 1)
			ra(a, bench);
		else
			pb(a, b, bench);
		i++;
	}
	while (*b)
		pa(b, a, bench);
}

void	complex_sort(t_stack_node **a, t_stack_node **b, t_bench *bench)
{
	int	size;
	int	max_bits;
	int	bit;

	set_stack_indices(*a);
	size = get_stack_size(*a);
	if (size <= 5)
	{
		sort_small(a, b, bench);
		return ;
	}
	max_bits = get_max_bits(size);
	bit = 0;
	while (bit < max_bits)
	{
		sort_bit(a, b, bench, bit);
		bit++;
	}
}
