/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgoulart <rgoulart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 17:57:15 by rgoulart          #+#    #+#             */
/*   Updated: 2026/06/04 21:06:45 by rgoulart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			index;
	unsigned char	*j;

	j = (unsigned char *)s;
	if (n == 0)
		return ;
	index = 0;
	while (index < n)
	{
		j[index] = 0;
		index++;
	}
}
