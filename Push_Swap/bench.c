/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgoulart <rgoulart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 12:37:39 by rgoulart          #+#    #+#             */
/*   Updated: 2026/07/13 12:37:39 by rgoulart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	putstr_fd(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(fd, str, i);
}

static void	putnbr_fd(int n, int fd)
{
	char	c;

	if (n == -2147483648)
	{
		putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n >= 10)
		putnbr_fd(n / 10, fd);
	c = (n % 10) + '0';
	write(fd, &c, 1);
}

void	init_bench(t_bench *bench)
{
	bench->disorder = 0.0;
	bench->total_ops = 0;
	bench->sa = 0;
	bench->sb = 0;
	bench->ss = 0;
	bench->pa = 0;
	bench->pb = 0;
	bench->ra = 0;
	bench->rb = 0;
	bench->rr = 0;
	bench->rra = 0;
	bench->rrb = 0;
	bench->rrr = 0;
	bench->bench_mode = 0;
	bench->strategy_type = 0;
}

static void	print_strategy(t_bench *bench)
{
	if (bench->strategy_type == 1)
		putstr_fd("Strategy: simple O(n^2)\n", 2);
	else if (bench->strategy_type == 2)
		putstr_fd("Strategy: medium O(n sqrt(n))\n", 2);
	else if (bench->strategy_type == 3)
		putstr_fd("Strategy: complex O(n log n)\n", 2);
	else
		putstr_fd("Strategy: adaptive\n", 2);
}

static void	print_op(char *name, int count)
{
	putstr_fd(name, 2);
	putstr_fd(": ", 2);
	putnbr_fd(count, 2);
	write(2, "\n", 1);
}

void	print_benchmark_report(t_bench *bench)
{
	int	percent;

	percent = (int)(bench->disorder * 10000.0 + 0.5);
	putstr_fd("Disorder: ", 2);
	putnbr_fd(percent / 100, 2);
	write(2, ".", 1);
	if (percent % 100 < 10)
		write(2, "0", 1);
	putnbr_fd(percent % 100, 2);
	putstr_fd("%\n", 2);
	print_strategy(bench);
	putstr_fd("Total operations: ", 2);
	putnbr_fd(bench->total_ops, 2);
	write(2, "\n", 1);
	print_op("sa", bench->sa);
	print_op("sb", bench->sb);
	print_op("ss", bench->ss);
	print_op("pa", bench->pa);
	print_op("pb", bench->pb);
	print_op("ra", bench->ra);
	print_op("rb", bench->rb);
	print_op("rr", bench->rr);
	print_op("rra", bench->rra);
	print_op("rrb", bench->rrb);
	print_op("rrr", bench->rrr);
}