/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder_metric.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgoulart <rgoulart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 14:04:00 by rgoulart          #+#    #+#             */
/*   Updated: 2026/07/12 20:13:30 by rgoulart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*stack_to_array(t_stack_node *head, int size)
{
	int				*array;
	int				i;
	t_stack_node	*curr;

	array = malloc(sizeof(int) * size);
	if (!array)
		return (NULL);
	i = 0;
	curr = head;
	while (i < size)
	{
		array[i] = curr->value;
		curr = curr->next;
		i++;
	}
	return (array);
}

static double	count_mistakes(int *arr, int size)
{
	int		i;
	int		j;
	double	mistakes;

	mistakes = 0.0;
	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] > arr[j])
				mistakes += 1.0;
			j++;
		}
		i++;
	}
	return (mistakes);
}

static double	calculate_final_ratio(double mistakes, int size)
{
	double	total_pairs;

	total_pairs = ((double)size * ((double)size - 1.0)) / 2.0;
	if (total_pairs == 0.0)
		return (0.0);
	return (mistakes / total_pairs);
}

double	compute_disorder(t_stack_node *a)
{
	int		*arr;
	int		size;
	double	mistakes;

	size = get_stack_size(a);
	if (size <= 1)
		return (0.0);
	arr = stack_to_array(a, size);
	if (!arr)
		return (0.0);
	mistakes = count_mistakes(arr, size);
	free(arr);
	return (calculate_final_ratio(mistakes, size));
}
