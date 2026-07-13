/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-alme <vde-alme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 14:08:18 by rgoulart          #+#    #+#             */
/*   Updated: 2026/07/12 21:10:15 by vde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack_node
{
	int					value;
	int					index;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

typedef struct s_bench
{
	double	disorder;
	int		total_ops;
	int		sa;
	int		sb;
	int		ss;
	int		pa;
	int		pb;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
	int		bench_mode;
	int		strategy_type;
}	t_bench;

int				ft_atoi_strict(const char *str, int *error);
int				check_duplicates(int *array, int size);
t_stack_node	*create_node(int value);
void			append_node(t_stack_node **head, t_stack_node *new_node);
void			free_stack(t_stack_node **head);
int				get_stack_size(t_stack_node *head);
void			swap(t_stack_node **head);
void			push(t_stack_node **src, t_stack_node **dst);
void			rotate(t_stack_node **head);
void			reverse_rotate(t_stack_node **head);

void			sa(t_stack_node **a, t_bench *bench);
void			sb(t_stack_node **b, t_bench *bench);
void			ss(t_stack_node **a, t_stack_node **b, t_bench *bench);
void			ra(t_stack_node **a, t_bench *bench);
void			rr(t_stack_node **a, t_stack_node **b, t_bench *bench);
void			rra(t_stack_node **a, t_bench *bench);
void			rrr(t_stack_node **a, t_stack_node **b, t_bench *bench);
void			pb(t_stack_node **a, t_stack_node **b, t_bench *bench);
void			rb(t_stack_node **b, t_bench *bench);
void			rrb(t_stack_node **b, t_bench *bench);
void			pa(t_stack_node **b, t_stack_node **a, t_bench *bench);

int				calculate_disorder_metric(t_stack_node *head);
void			set_stack_indices(t_stack_node *head);
int				ft_sqrt(int number);
void			sort_three(t_stack_node **a);
void			sort_small(t_stack_node **a, t_stack_node **b);
void			medium_sort(t_stack_node **a, t_stack_node **b);
void			complex_sort(t_stack_node **a, t_stack_node **b);

#endif