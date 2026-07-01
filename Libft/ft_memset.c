/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgoulart <rgoulart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 14:34:46 by rgoulart          #+#    #+#             */
/*   Updated: 2026/06/04 21:07:42 by rgoulart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			index;
	unsigned char	*j;

	j = (unsigned char *)b;
	if (len == 0)
		return (b);
	index = 0;
	while (index < len)
	{
		j[index] = c;
		index++;
	}
	return (b);
}
