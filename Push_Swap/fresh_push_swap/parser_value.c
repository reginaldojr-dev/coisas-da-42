/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_value.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-alme <vde-alme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 10:32:23 by vde-alme          #+#    #+#             */
/*   Updated: 2026/07/14 14:37:25 by vde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	reserve_values(t_input *in, int need)
{
	int	*new_values;
	int	i;

	if (need <= in->size)
		return (1);
	new_values = malloc(sizeof(int) * need);
	if (!new_values)
		return (0);
	i = 0;
	while (i < in->size)
	{
		new_values[i] = in->values[i];
		i++;
	}
	free(in->values);
	in->values = new_values;
	return (1);
}

static int	read_sign(const char *s, int len, int *i, int *sign)
{
	*i = 0;
	*sign = 1;
	if (*i < len && (s[*i] == '+' || s[*i] == '-'))
	{
		if (s[*i] == '-')
			*sign = -1;
		(*i)++;
	}
	return (*i < len);
}

int	ps_parse_int_token(const char *s, int len, int *out)
{
	long	n;
	long	limit;
	int		i;
	int		sign;

	n = 0;
	if (!read_sign(s, len, &i, &sign))
		return (0);
	limit = 2147483647L;
	if (sign == -1)
		limit = 2147483648L;
	while (i < len)
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		if (n > (limit - (s[i] - '0')) / 10)
			return (0);
		n = n * 10 + (s[i++] - '0');
	}
	*out = (int)(n * sign);
	return (1);
}

int	ps_add_value(t_input *in, int value)
{
	int	i;

	i = 0;
	while (i < in->size)
	{
		if (in->values[i] == value)
			return (0);
		i++;
	}
	if (!reserve_values(in, in->size + 1))
		return (0);
	in->values[in->size++] = value;
	return (1);
}