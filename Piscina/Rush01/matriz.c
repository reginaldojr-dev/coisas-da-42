/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matriz.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgoulart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 16:09:43 by rgoulart          #+#    #+#             */
/*   Updated: 2026/03/07 17:16:26 by rgoulart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	g_matriz[4][4];

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_matriz(void)
{
	int	row;
	int	col;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (colunm < 4)
		{
			ft_putchar(g_matriz[row][col] + '0');
			col++;
		}
		ft_putchar('\n');
		row++;
	}
}
