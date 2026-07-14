#include "push_swap.h"

static int	add_number_token(char *start, int len, t_input *in)
{
	char	save;
	int		value;

	save = start[len];
	start[len] = '\0';
	if (!ps_parse_int_token(start, len, &value))
	{
		start[len] = save;
		return (0);
	}
	start[len] = save;
	return (ps_add_value(in, value));
}

static int	parse_number_arg(char *arg, t_input *in)
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
		if (j > start && !add_number_token(&arg[start], j - start, in))
			return (0);
	}
	return (1);
}

int	checker_parse_input(int argc, char **argv, t_input *in)
{
	int	i;

	in->values = NULL;
	in->size = 0;
	in->bench = 0;
	in->strategy = STRAT_ADAPTIVE;
	i = 1;
	while (i < argc)
	{
		if (!parse_number_arg(argv[i], in))
			return (0);
		i++;
	}
	return (1);
}
