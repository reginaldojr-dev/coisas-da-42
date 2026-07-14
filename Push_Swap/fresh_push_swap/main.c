/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgoulart <rgoulart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 10:32:23 by rgoulart          #+#    #+#             */
/*   Updated: 2026/07/14 14:37:25 by rgoulart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	init_ctx(t_ctx *ctx, t_input *in)
{
	int	i;

	ctx->a.data = malloc(sizeof(int) * in->size);
	ctx->b.data = malloc(sizeof(int) * in->size);
	if (!ctx->a.data || !ctx->b.data)
	{
		free(ctx->a.data);
		free(ctx->b.data);
		return (0);
	}
	ctx->a.size = in->size;
	ctx->a.cap = in->size;
	ctx->b.size = 0;
	ctx->b.cap = in->size;
	i = 0;
	while (i < 11)
		ctx->stats.count[i++] = 0;
	ctx->stats.total = 0;
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
	ctx->a.data = NULL;
	ctx->b.data = NULL;
}

static void	run_strategy(t_ctx *ctx, t_strategy strategy, double disorder)
{
	if (is_sorted(&ctx->a))
		return ;
	if (strategy == STRAT_SIMPLE)
		sort_simple(ctx);
	else if (strategy == STRAT_MEDIUM)
		sort_medium(ctx);
	else if (strategy == STRAT_COMPLEX)
		sort_complex(ctx);
	else
		sort_adaptive(ctx, disorder);
}

int	main(int argc, char **argv)
{
	t_input	in;
	t_ctx	ctx;
	double	disorder;

	if (argc == 1)
		return (0);
	if (!parse_input(argc, argv, &in))
		error_exit(&in);
	if (in.size == 0)
		return (free_input(&in), 0);
	disorder = compute_disorder(in.values, in.size);
	if (!prepare_indices(&in) || !init_ctx(&ctx, &in))
		error_exit(&in);
	run_strategy(&ctx, in.strategy, disorder);
	if (in.bench)
		print_bench(&ctx, in.strategy, disorder);
	free_ctx(&ctx);
	free_input(&in);
	return (0);
}