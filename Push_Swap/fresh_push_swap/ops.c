/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgoulart <rgoulart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 10:32:23 by rgoulart          #+#    #+#             */
/*   Updated: 2026/07/14 14:37:25 by rgoulart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_swap_top(t_stack *s)
{
	int	tmp;

	if (s->size < 2)
		return ;
	tmp = s->data[0];
	s->data[0] = s->data[1];
	s->data[1] = tmp;
}

void	op_push_to(t_stack *dst, t_stack *src)
{
	int	i;
	int	value;

	if (src->size < 1)
		return ;
	value = src->data[0];
	i = 0;
	while (i + 1 < src->size)
	{
		src->data[i] = src->data[i + 1];
		i++;
	}
	src->size--;
	i = dst->size;
	while (i > 0)
	{
		dst->data[i] = dst->data[i - 1];
		i--;
	}
	dst->data[0] = value;
	dst->size++;
}

void	op_rotate_up(t_stack *s)
{
	int	i;
	int	first;

	if (s->size < 2)
		return ;
	first = s->data[0];
	i = 0;
	while (i + 1 < s->size)
	{
		s->data[i] = s->data[i + 1];
		i++;
	}
	s->data[s->size - 1] = first;
}

void	op_rotate_down(t_stack *s)
{
	int	i;
	int	last;

	if (s->size < 2)
		return ;
	last = s->data[s->size - 1];
	i = s->size - 1;
	while (i > 0)
	{
		s->data[i] = s->data[i - 1];
		i--;
	}
	s->data[0] = last;
}

void	op_apply(t_ctx *ctx, t_op op)
{
	if (op == OP_SA || op == OP_SS)
		op_swap_top(&ctx->a);
	if (op == OP_SB || op == OP_SS)
		op_swap_top(&ctx->b);
	if (op == OP_PA)
		op_push_to(&ctx->a, &ctx->b);
	if (op == OP_PB)
		op_push_to(&ctx->b, &ctx->a);
	if (op == OP_RA || op == OP_RR)
		op_rotate_up(&ctx->a);
	if (op == OP_RB || op == OP_RR)
		op_rotate_up(&ctx->b);
	if (op == OP_RRA || op == OP_RRR)
		op_rotate_down(&ctx->a);
	if (op == OP_RRB || op == OP_RRR)
		op_rotate_down(&ctx->b);
	ctx->stats.count[op]++;
	ctx->stats.total++;
	ft_putstr_fd(1, op_name(op));
}