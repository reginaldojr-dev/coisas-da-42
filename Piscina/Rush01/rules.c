/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgoulart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 16:26:47 by rgoulart          #+#    #+#             */
/*   Updated: 2026/03/07 18:59:16 by rgoulart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	g_matriz[4][4];

void	ft_check_row(int row, int num)
{
	int	i;

	i = 0;
	while (row < 4)
	{
		if (g_matriz[row][i] == num)
		return (0);
		i++;
	}
	return (1);
}

void	ft_check_col(int col, int num)
{
	int	i;

	i = 0;
	while (col < 4)
	{
		if (g_matriz[col][i] == num)
		return (0);
		i++;
	}
	return (1);
}
