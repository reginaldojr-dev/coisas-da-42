#include "push_swap.h"

static void	init_input(t_input *in)
{
	in->values = NULL;
	in->size = 0;
	in->bench = 0;
	in->strategy = STRAT_ADAPTIVE;
}

static int	parse_arg(char *arg, t_input *in)
{
	int	j;
	int	start;

	if (ps_count_tokens(arg) == 0)
		return (0);
	j = 0;
	while (arg[j])
	{
		while (ft_isspace(arg[j]))
			j++;
		start = j;
		while (arg[j] && !ft_isspace(arg[j]))
			j++;
		if (j > start && !ps_add_token(&arg[start], j - start, in))
			return (0);
	}
	return (1);
}

int	parse_input(int argc, char **argv, t_input *in)
{
	int	i;

	init_input(in);
	i = 1;
	while (i < argc)
	{
		if (!parse_arg(argv[i], in))
			return (0);
		i++;
	}
	return (1);
}

void	free_input(t_input *in)
{
	free(in->values);
	in->values = NULL;
	in->size = 0;
}
