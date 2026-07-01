/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgoulart <rgoulart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 14:02:13 by rgoulart          #+#    #+#             */
/*   Updated: 2026/06/04 21:07:30 by rgoulart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*j;
	unsigned char	*k;
	size_t			i;

	j = (unsigned char *)s1;
	k = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (j[i] != k[i])
		{
			return ((unsigned char)j[i] - (unsigned char)k[i]);
		}
		i++;
	}
	return (0);
}
