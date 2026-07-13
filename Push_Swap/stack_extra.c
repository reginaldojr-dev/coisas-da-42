/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_extra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgoulart <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 12:34:17 by rgoulart          #+#    #+#             */
/*   Updated: 2026/07/13 12:34:17 by rgoulart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_stack_size(t_stack_node *head)
{
	t_stack_node	*curr;
	int				size;

	if (!head)
		return (0);
	size = 1;
	curr = head->next;
	while (curr != head)
	{
		size++;
		curr = curr->next;
	}
	return (size);
}

int	is_already_sorted(t_stack_node *a)
{
	t_stack_node	*curr;

	if (!a)
		return (1);
	curr = a;
	while (curr->next != a)
	{
		if (curr->value > curr->next->value)
			return (0);
		curr = curr->next;
	}
	return (1);
}

int	parse_to_array(char **argv, int size, int *array)
{
	int	i;
	int	error;

	i = 0;
	while (i < size)
	{
		error = 0;
		array[i] = ft_atoi_strict(argv[i], &error);
		if (error)
			return (0);
		i++;
	}
	if (check_duplicates(array, size))
		return (0);
	return (1);
}

int	fill_stack_from_array(t_stack_node **a, int *array, int size)
{
	t_stack_node	*node;
	int				i;

	i = 0;
	while (i < size)
	{
		node = create_node(array[i]);
		if (!node)
		{
			free_stack(a);
			return (0);
		}
		append_node(a, node);
		i++;
	}
	return (1);
}