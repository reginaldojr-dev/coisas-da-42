/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_wrappers_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-alme <vde-alme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 14:06:46 by rgoulart          #+#    #+#             */
/*   Updated: 2026/07/12 21:10:12 by vde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_stack_node **b, t_bench *bench)
{
	swap(b);
	if (bench)
	{
		bench->sb++;
		bench->total_ops++;
	}
	write(1, "sb\n", 3);
}

void	rb(t_stack_node **b, t_bench *bench)
{
	rotate(b);
	if (bench)
	{
		bench->rb++;
		bench->total_ops++;
	}
	write(1, "rb\n", 3);
}

void	rrb(t_stack_node **b, t_bench *bench)
{
	reverse_rotate(b);
	if (bench)
	{
		bench->rrb++;
		bench->total_ops++;
	}
	write(1, "rrb\n", 4);
}

void	pa(t_stack_node **b, t_stack_node **a, t_bench *bench)
{
	push(b, a);
	if (bench)
	{
		bench->pa++;
		bench->total_ops++;
	}
	write(1, "pa\n", 3);
}
