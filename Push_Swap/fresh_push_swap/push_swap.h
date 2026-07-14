#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef enum e_strategy
{
	STRAT_ADAPTIVE,
	STRAT_SIMPLE,
	STRAT_MEDIUM,
	STRAT_COMPLEX
}	t_strategy;

typedef enum e_op
{
	OP_SA,
	OP_SB,
	OP_SS,
	OP_PA,
	OP_PB,
	OP_RA,
	OP_RB,
	OP_RR,
	OP_RRA,
	OP_RRB,
	OP_RRR
}	t_op;

typedef struct s_stack
{
	int	*data;
	int	size;
	int	cap;
}	t_stack;

typedef struct s_stats
{
	long	count[11];
	long	total;
}	t_stats;

typedef struct s_input
{
	int			*values;
	int			size;
	int			bench;
	t_strategy	strategy;
}	t_input;

typedef struct s_ctx
{
	t_stack	a;
	t_stack	b;
	t_stats	stats;
}	t_ctx;

int			parse_input(int argc, char **argv, t_input *in);
void		free_input(t_input *in);
int			ps_count_tokens(char *s);
int			ps_add_token(char *start, int len, t_input *in);
int			ps_parse_int_token(const char *s, int len, int *out);
int			ps_add_value(t_input *in, int value);
int			prepare_indices(t_input *in);
double		compute_disorder(int *arr, int n);
int			is_sorted(t_stack *s);
void		error_exit(t_input *in);

void		op_apply(t_ctx *ctx, t_op op);
void		sort_small(t_ctx *ctx);
void		sort_simple(t_ctx *ctx);
void		sort_medium(t_ctx *ctx);
void		sort_complex(t_ctx *ctx);
void		sort_chunk_range(t_ctx *ctx, int range);
void		sort_adaptive(t_ctx *ctx, double disorder);

void		print_bench(t_ctx *ctx, t_strategy strategy, double disorder);
const char	*strategy_name(t_strategy strategy);
const char	*strategy_complexity(t_strategy strategy);

int			ft_isspace(char c);
int			ft_streq(const char *a, const char *b);
int			ft_strlen(const char *s);
void		ft_putstr_fd(int fd, const char *s);
void		ft_putnbr_fd(int fd, long n);

#endif
