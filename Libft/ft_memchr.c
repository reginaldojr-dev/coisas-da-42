/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgoulart <rgoulart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 12:10:48 by rgoulart          #+#    #+#             */
/*   Updated: 2026/06/04 21:07:25 by rgoulart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*j;
	size_t			i;

	j = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (j[i] == (unsigned char)c)
			return ((void *)&j[i]);
		i++;
	}
	return (NULL);
}
