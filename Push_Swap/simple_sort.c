/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgoulart <rgoulart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 14:08:31 by rgoulart          #+#    #+#             */
/*   Updated: 2026/07/12 14:08:36 by rgoulart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack_node **a, t_bench *bench)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->prev->value;
	if (first > second && first > third)
		ra(a, bench);
	else if (second > first && second > third)
		rra(a, bench);
	first = (*a)->value;
	second = (*a)->next->value;
	if (first > second)
		sa(a, bench);
}

static int	get_min_pos(t_stack_node *head, int min_val)
{
	t_stack_node	*curr;
	int				pos;

	pos = 0;
	curr = head;
	while (curr->value != min_val)
	{
		pos++;
		curr = curr->next;
	}
	return (pos);
}

static int	find_min_value(t_stack_node *head)
{
	t_stack_node	*curr;
	int				min;

	min = head->value;
	curr = head->next;
	while (curr != head)
	{
		if (curr->value < min)
			min = curr->value;
		curr = curr->next;
	}
	return (min);
}

static void	push_min_to_b(t_stack_node **a, t_stack_node **b, t_bench *bench)
{
	int	min;
	int	size;
	int	pos;

	min = find_min_value(*a);
	size = get_stack_size(*a);
	pos = get_min_pos(*a, min);
	if (pos <= size / 2)
	{
		while ((*a)->value != min)
			ra(a, bench);
	}
	else
	{
		while ((*a)->value != min)
			rra(a, bench);
	}
	pb(a, b, bench);
}

void	sort_small(t_stack_node **a, t_stack_node **b, t_bench *bench)
{
	int	size;

	size = get_stack_size(*a);
	if (size == 2)
	{
		if ((*a)->value > (*a)->next->value)
			sa(a, bench);
		return ;
	}
	while (get_stack_size(*a) > 3)
		push_min_to_b(a, b, bench);
	if (get_stack_size(*a) == 3)
		sort_three(a, bench);
	while (*b)
		pa(b, a, bench);
}
