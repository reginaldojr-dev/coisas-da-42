#include "push_swap.h"

static int	int_sqrt(int n)
{
	int	x;

	x = 1;
	while ((x + 1) * (x + 1) <= n)
		x++;
	return (x);
}

static int	find_next_in_range(t_stack *s, int limit)
{
	int	i;

	i = 0;
	while (i < s->size)
	{
		if (s->data[i] <= limit)
			return (i);
		i++;
	}
	return (0);
}

static int	pos_max(t_stack *s)
{
	int	i;
	int	pos;

	i = 1;
	pos = 0;
	while (i < s->size)
	{
		if (s->data[i] > s->data[pos])
			pos = i;
		i++;
	}
	return (pos);
}

static void	move_b_pos_top(t_ctx *ctx, int pos)
{
	if (pos <= ctx->b.size / 2)
		while (pos-- > 0)
			op_apply(ctx, OP_RB);
	else
		while (pos++ < ctx->b.size)
			op_apply(ctx, OP_RRB);
}

static void	chunk_sort(t_ctx *ctx, int range)
{
	int	pushed;
	int	pos;
	int	limit;

	if (ctx->a.size <= 5)
	{
		sort_small(ctx);
		return ;
	}
	pushed = 0;
	while (ctx->a.size > 0)
	{
		limit = pushed + range;
		if (ctx->a.data[0] <= pushed)
		{
			op_apply(ctx, OP_PB);
			if (ctx->b.size > 1)
				op_apply(ctx, OP_RB);
			pushed++;
		}
		else if (ctx->a.data[0] <= limit)
		{
			op_apply(ctx, OP_PB);
			pushed++;
		}
		else
		{
			pos = find_next_in_range(&ctx->a, limit);
			if (pos <= ctx->a.size / 2)
				op_apply(ctx, OP_RA);
			else
				op_apply(ctx, OP_RRA);
		}
	}
	while (ctx->b.size > 0)
	{
		move_b_pos_top(ctx, pos_max(&ctx->b));
		op_apply(ctx, OP_PA);
	}
}

void	sort_simple(t_ctx *ctx)
{
	int	range;

	range = int_sqrt(ctx->a.size) * 2;
	if (range < 10)
		range = 10;
	chunk_sort(ctx, range);
}

void	sort_medium(t_ctx *ctx)
{
	int	range;

	range = int_sqrt(ctx->a.size) * 14 / 10 + 2;
	if (range < 8)
		range = 8;
	chunk_sort(ctx, range);
}

void	sort_adaptive(t_ctx *ctx, double disorder)
{
	int	range;

	if (disorder >= 0.50)
		return (sort_complex(ctx));
	if (disorder < 0.20)
		range = int_sqrt(ctx->a.size) * 2 + 5;
	else
		range = int_sqrt(ctx->a.size) * 14 / 10 + 2;
	if (range < 8)
		range = 8;
	chunk_sort(ctx, range);
}
