/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgoulart <rgoulart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 04:19:09 by rgoulart          #+#    #+#             */
/*   Updated: 2026/07/12 21:15:11 by rgoulart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	setup_stack(char **argv, int size, t_stack_node **a)
{
	int	*array;

	array = malloc(sizeof(int) * size);
	if (!array)
		return (0);
	if (!parse_to_array(argv, size, array)
		|| !fill_stack_from_array(a, array, size))
	{
		free(array);
		return (0);
	}
	free(array);
	return (1);
}

static void	dispatch_strategy(t_stack_node **a, t_stack_node **b, t_bench *bch)
{
	int	strat;

	strat = bch->strategy_type;
	if (strat == 0)
	{
		if (bch->disorder < 0.2)
			strat = 1;
		else if (bch->disorder < 0.5)
			strat = 2;
		else
			strat = 3;
	}
	if (strat == 1)
		execute_simple_sort(a, b, bch);
	else if (strat == 2)
		execute_medium_sort(a, b, bch);
	else if (strat == 3)
		execute_complex_sort(a, b, bch);
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	t_bench			bench;
	int				i;

	if (argc < 2)
		return (0);
	a = NULL;
	b = NULL;
	i = 1;
	init_bench(&bench);
	if (!parse_flags(argv, &i, &bench) || i == argc
		|| !setup_stack(argv + i, argc - i, &a))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	bench.disorder = compute_disorder(a);
	if (!is_already_sorted(a))
		dispatch_strategy(&a, &b, &bench);
	if (bench.bench_mode)
		print_benchmark_report(&bench);
	free(stack(&a));
	return (0);
}
