#include "push_swap.h"

static const char	*g_names[11] = {
	"sa\n", "sb\n", "ss\n", "pa\n", "pb\n", "ra\n",
	"rb\n", "rr\n", "rra\n", "rrb\n", "rrr\n"
};

static void	swap_top(t_stack *s)
{
	int	tmp;

	if (s->size < 2)
		return ;
	tmp = s->data[0];
	s->data[0] = s->data[1];
	s->data[1] = tmp;
}

static void	push_to(t_stack *dst, t_stack *src)
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

static void	rotate_up(t_stack *s)
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

static void	rotate_down(t_stack *s)
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
		swap_top(&ctx->a);
	if (op == OP_SB || op == OP_SS)
		swap_top(&ctx->b);
	if (op == OP_PA)
		push_to(&ctx->a, &ctx->b);
	if (op == OP_PB)
		push_to(&ctx->b, &ctx->a);
	if (op == OP_RA || op == OP_RR)
		rotate_up(&ctx->a);
	if (op == OP_RB || op == OP_RR)
		rotate_up(&ctx->b);
	if (op == OP_RRA || op == OP_RRR)
		rotate_down(&ctx->a);
	if (op == OP_RRB || op == OP_RRR)
		rotate_down(&ctx->b);
	ctx->stats.count[op]++;
	ctx->stats.total++;
	ft_putstr_fd(1, g_names[op]);
}
