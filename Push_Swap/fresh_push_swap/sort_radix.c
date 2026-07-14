/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-alme <vde-alme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 10:32:23 by vde-alme          #+#    #+#             */
/*   Updated: 2026/07/14 14:37:25 by vde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	radix_sort(t_ctx *ctx)
{
	int	max;
	int	bits;
	int	bit;
	int	i;
	int	size;

	if (ctx->a.size <= 5)
	{
		sort_small(ctx);
		return ;
	}
	max = ctx->a.size - 1;
	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	bit = 0;
	while (bit < bits)
	{
		size = ctx->a.size;
		i = 0;
		while (i++ < size)
		{
			if (((ctx->a.data[0] >> bit) & 1) == 1)
				op_apply(ctx, OP_RA);
			else
				op_apply(ctx, OP_PB);
		}
		while (ctx->b.size > 0)
			op_apply(ctx, OP_PA);
		bit++;
	}
}

void	sort_complex(t_ctx *ctx)
{
	int	range;

	if (ctx->a.size <= 5)
	{
		sort_small(ctx);
		return ;
	}
	if (ctx->a.size <= 500)
	{
		range = 14;
		if (ctx->a.size > 200)
			range = 32;
		sort_chunk_range(ctx, range);
		return ;
	}
	radix_sort(ctx);
}