/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgoulart <rgoulart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 21:17:47 by rgoulart          #+#    #+#             */
/*   Updated: 2026/07/12 21:34:27 by rgoulart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include "push_swap.h"

static int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

int	parse_flags(char **argv, int *i, t_bench *bench)
{
	int	strategy_seen;

	strategy_seen = 0;
	while (argv[*i] && argv[*i][0] == '-' && argv[*i][1] == '-')
	{
		if (ft_strcmp(argv[*i], "--bench") == 0)
			bench->bench_mode = 1;
		else if (ft_strcmp(argv[*i], "--simple") == 0 && !strategy_seen++)
			bench->strategy_type = 1;
		else if (ft_strcmp(argv[*i], "--medium") == 0 && !strategy_seen++)
			bench->strategy_type = 2;
		else if (ft_strcmp(argv[*i], "--complex") == 0 && !strategy_seen++)
			bench->strategy_type = 3;
		else if (ft_strcmp(argv[*i], "--adaptive") == 0 && !strategy_seen++)
			bench->strategy_type = 0;
		else
			return (0);
		(*i)++;
	}
	return (1);
}
