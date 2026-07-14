/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_name.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgoulart <rgoulart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 10:32:23 by rgoulart          #+#    #+#             */
/*   Updated: 2026/07/14 14:37:25 by rgoulart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

const char	*op_name(t_op op)
{
	const char	*names[11];

	names[OP_SA] = "sa\n";
	names[OP_SB] = "sb\n";
	names[OP_SS] = "ss\n";
	names[OP_PA] = "pa\n";
	names[OP_PB] = "pb\n";
	names[OP_RA] = "ra\n";
	names[OP_RB] = "rb\n";
	names[OP_RR] = "rr\n";
	names[OP_RRA] = "rra\n";
	names[OP_RRB] = "rrb\n";
	names[OP_RRR] = "rrr\n";
	return (names[op]);
}