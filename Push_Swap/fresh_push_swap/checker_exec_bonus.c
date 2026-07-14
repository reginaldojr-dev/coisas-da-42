/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_exec_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-alme <vde-alme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 10:32:23 by vde-alme          #+#    #+#             */
/*   Updated: 2026/07/14 14:37:25 by vde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	op_from_line(char *line, t_op *op)
{
	int	i;

	i = 0;
	while (i < 11)
	{
		if (ft_streq(line, op_name((t_op)i)))
		{
			*op = (t_op)i;
			return (1);
		}
		i++;
	}
	return (0);
}

void	checker_apply(t_ctx *ctx, t_op op)
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
}

int	checker_run_ops(t_ctx *ctx)
{
	char	*line;
	t_op	op;
	int		ret;

	ret = checker_read_line(&line);
	while (ret > 0)
	{
		if (!op_from_line(line, &op))
			return (free(line), 0);
		checker_apply(ctx, op);
		free(line);
		ret = checker_read_line(&line);
	}
	return (ret == 0);
}