/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgoulart <rgoulart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 14:04:29 by rgoulart          #+#    #+#             */
/*   Updated: 2026/07/12 14:05:43 by rgoulart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sqrt(int number)
{
	int	i;

	if (number < 0)
		return (0);
	i = 1;
	while (i * i <= number)
	{
		if (i * i == number || (i + 1) * (i + 1) > number)
			return (i);
		i++;
	}
	return (i);
}
