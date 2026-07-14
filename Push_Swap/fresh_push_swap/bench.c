#include "push_swap.h"

static const char	*g_ops[11] = {
	"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr", "rra", "rrb", "rrr"
};

const char	*strategy_name(t_strategy strategy)
{
	if (strategy == STRAT_SIMPLE)
		return ("simple");
	if (strategy == STRAT_MEDIUM)
		return ("medium");
	if (strategy == STRAT_COMPLEX)
		return ("complex");
	return ("adaptive");
}

const char	*strategy_complexity(t_strategy strategy)
{
	if (strategy == STRAT_SIMPLE)
		return ("O(n^2)");
	if (strategy == STRAT_MEDIUM)
		return ("O(n sqrt(n))");
	if (strategy == STRAT_COMPLEX)
		return ("O(n log n)");
	return ("adaptive");
}

static void	put_percent(double value)
{
	long	scaled;

	scaled = (long)(value * 10000.0 + 0.5);
	ft_putnbr_fd(2, scaled / 100);
	ft_putstr_fd(2, ".");
	if (scaled % 100 < 10)
		ft_putstr_fd(2, "0");
	ft_putnbr_fd(2, scaled % 100);
	ft_putstr_fd(2, "%");
}

void	print_bench(t_ctx *ctx, t_strategy strategy, double disorder)
{
	int	i;

	ft_putstr_fd(2, "[bench] strategy: ");
	ft_putstr_fd(2, strategy_name(strategy));
	ft_putstr_fd(2, " ");
	ft_putstr_fd(2, strategy_complexity(strategy));
	ft_putstr_fd(2, "\n[bench] disorder: ");
	put_percent(disorder);
	ft_putstr_fd(2, "\n[bench] operations: ");
	ft_putnbr_fd(2, ctx->stats.total);
	ft_putstr_fd(2, "\n");
	i = 0;
	while (i < 11)
	{
		ft_putstr_fd(2, "[bench] ");
		ft_putstr_fd(2, g_ops[i]);
		ft_putstr_fd(2, ": ");
		ft_putnbr_fd(2, ctx->stats.count[i]);
		ft_putstr_fd(2, "\n");
		i++;
	}
}
