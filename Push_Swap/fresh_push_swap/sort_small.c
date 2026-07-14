/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgoulart <rgoulart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 10:32:23 by rgoulart          #+#    #+#             */
/*   Updated: 2026/07/14 14:37:25 by rgoulart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	pos_min(t_stack *s)
{
	int	i;
	int	pos;

	i = 1;
	pos = 0;
	while (i < s->size)
	{
		if (s->data[i] < s->data[pos])
			pos = i;
		i++;
	}
	return (pos);
}

static void	move_a_pos_top(t_ctx *ctx, int pos)
{
	if (pos <= ctx->a.size / 2)
		while (pos-- > 0)
			op_apply(ctx, OP_RA);
	else
		while (pos++ < ctx->a.size)
			op_apply(ctx, OP_RRA);
}

static void	sort_three(t_ctx *ctx)
{
	int	a;
	int	b;
	int	c;

	if (ctx->a.size < 3)
	{
		if (ctx->a.size == 2 && ctx->a.data[0] > ctx->a.data[1])
			op_apply(ctx, OP_SA);
		return ;
	}
	a = ctx->a.data[0];
	b = ctx->a.data[1];
	c = ctx->a.data[2];
	if (a > b && b < c && a < c)
		op_apply(ctx, OP_SA);
	else if (a > b && b > c)
	{
		op_apply(ctx, OP_SA);
		op_apply(ctx, OP_RRA);
	}
	else if (a > b && b < c && a > c)
		op_apply(ctx, OP_RA);
	else if (a < b && b > c && a < c)
	{
		op_apply(ctx, OP_SA);
		op_apply(ctx, OP_RA);
	}
	else if (a < b && b > c && a > c)
		op_apply(ctx, OP_RRA);
}

void	sort_small(t_ctx *ctx)
{
	int	target;

	if (is_sorted(&ctx->a))
		return ;
	while (ctx->a.size > 3)
	{
		target = pos_min(&ctx->a);
		move_a_pos_top(ctx, target);
		op_apply(ctx, OP_PB);
	}
	sort_three(ctx);
	while (ctx->b.size > 0)
		op_apply(ctx, OP_PA);
}