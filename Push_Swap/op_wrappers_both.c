/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_wrappers_both.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgoulart <rgoulart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 20:37:15 by vde-alme          #+#    #+#             */
/*   Updated: 2026/07/12 21:15:45 by rgoulart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_stack_node **b, t_stack_node **a, t_bench *bench)
{
	swap(a);
	swap(b);
	if (bench)
	{
		bench->ss++;
		bench->total_ops++;
	}
	write(1, "ss\n", 3);
}

void	rr(t_stack_node **b, t_stack_node **a, t_bench *bench)
{
	rotate(a);
	rotate(b);
	if (bench)
	{
		bench->rr++;
		bench->total_ops++;
	}
	write(1, "rr\n", 3);
}

void	rrr(t_stack_node **b, t_stack_node **a, t_bench *bench)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (bench)
	{
		bench->rrr++;
		bench->total_ops++;
	}
	write(1, "rrr\n", 4);
}
