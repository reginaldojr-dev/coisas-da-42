/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgoulart <rgoulart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 10:32:23 by rgoulart          #+#    #+#             */
/*   Updated: 2026/07/14 14:37:25 by rgoulart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_copy(int *copy, int n)
{
	int	i;
	int	j;
	int	key;

	i = 1;
	while (i < n)
	{
		key = copy[i];
		j = i - 1;
		while (j >= 0 && copy[j] > key)
		{
			copy[j + 1] = copy[j];
			j--;
		}
		copy[j + 1] = key;
		i++;
	}
}

static int	find_rank(int *copy, int n, int value)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (copy[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

int	prepare_indices(t_input *in)
{
	int	*copy;
	int	i;

	copy = malloc(sizeof(int) * in->size);
	if (!copy)
		return (0);
	i = 0;
	while (i < in->size)
	{
		copy[i] = in->values[i];
		i++;
	}
	sort_copy(copy, in->size);
	i = 0;
	while (i < in->size)
	{
		in->values[i] = find_rank(copy, in->size, in->values[i]);
		i++;
	}
	free(copy);
	return (1);
}

double	compute_disorder(int *arr, int n)
{
	long long	mistakes;
	long long	total;
	int			i;
	int			j;

	if (n < 2)
		return (0.0);
	mistakes = 0;
	total = 0;
	i = 0;
	while (i < n)
	{
		j = i + 1;
		while (j < n)
		{
			if (arr[i] > arr[j])
				mistakes++;
			total++;
			j++;
		}
		i++;
	}
	return ((double)mistakes / (double)total);
}

int	is_sorted(t_stack *s)
{
	int	i;

	i = 1;
	while (i < s->size)
	{
		if (s->data[i - 1] > s->data[i])
			return (0);
		i++;
	}
	return (1);
}