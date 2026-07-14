/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-alme <vde-alme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 10:32:23 by vde-alme          #+#    #+#             */
/*   Updated: 2026/07/14 14:37:25 by vde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	init_ctx(t_ctx *ctx, t_input *in)
{
	int	i;

	ctx->a.data = malloc(sizeof(int) * in->size);
	ctx->b.data = malloc(sizeof(int) * in->size);
	if (!ctx->a.data || !ctx->b.data)
		return (free(ctx->a.data), free(ctx->b.data), 0);
	ctx->a.size = in->size;
	ctx->a.cap = in->size;
	ctx->b.size = 0;
	ctx->b.cap = in->size;
	i = 0;
	while (i < in->size)
	{
		ctx->a.data[i] = in->values[i];
		i++;
	}
	return (1);
}

static void	free_ctx(t_ctx *ctx)
{
	free(ctx->a.data);
	free(ctx->b.data);
}

static void	checker_error(t_input *in)
{
	free_input(in);
	ft_putstr_fd(2, "Error\n");
	exit(1);
}

static int	is_ok(t_ctx *ctx)
{
	return (ctx->b.size == 0 && is_sorted(&ctx->a));
}

int	main(int argc, char **argv)
{
	t_input	in;
	t_ctx	ctx;

	if (argc == 1)
		return (0);
	if (!checker_parse_input(argc, argv, &in))
		checker_error(&in);
	if (!prepare_indices(&in) || !init_ctx(&ctx, &in))
		checker_error(&in);
	if (!checker_run_ops(&ctx))
	{
		free_ctx(&ctx);
		checker_error(&in);
	}
	if (is_ok(&ctx))
		ft_putstr_fd(1, "OK\n");
	else
		ft_putstr_fd(1, "KO\n");
	free_ctx(&ctx);
	free_input(&in);
	return (0);
}