#include "push_swap.h"

int	ps_count_tokens(char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (ft_isspace(s[i]))
			i++;
		if (s[i])
			count++;
		while (s[i] && !ft_isspace(s[i]))
			i++;
	}
	return (count);
}

static int	handle_flag(char *s, int len, t_input *in)
{
	if (len == 7 && ft_streq(s, "--bench"))
		in->bench = 1;
	else if (len == 8 && ft_streq(s, "--simple"))
		in->strategy = STRAT_SIMPLE;
	else if (len == 8 && ft_streq(s, "--medium"))
		in->strategy = STRAT_MEDIUM;
	else if (len == 9 && ft_streq(s, "--complex"))
		in->strategy = STRAT_COMPLEX;
	else if (len == 10 && ft_streq(s, "--adaptive"))
		in->strategy = STRAT_ADAPTIVE;
	else
		return (0);
	return (1);
}

static int	restore_token(char *start, int len, char save, int ret)
{
	start[len] = save;
	return (ret);
}

int	ps_add_token(char *start, int len, t_input *in)
{
	char	save;
	int		value;

	save = start[len];
	start[len] = '\0';
	if (handle_flag(start, len, in))
		return (restore_token(start, len, save, 1));
	if (!ps_parse_int_token(start, len, &value))
		return (restore_token(start, len, save, 0));
	if (!ps_add_value(in, value))
		return (restore_token(start, len, save, 0));
	return (restore_token(start, len, save, 1));
}
