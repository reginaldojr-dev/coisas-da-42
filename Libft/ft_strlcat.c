/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgoulart <rgoulart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 13:27:26 by rgoulart          #+#    #+#             */
/*   Updated: 2026/06/04 21:36:56 by rgoulart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t destsize)
{
	size_t	len_dest;
	size_t	len_src;
	size_t	i;

	len_dest = 0;
	len_src = 0;
	while (src[len_src] != '\0')
		len_src++;
	while (dest[len_dest] && len_dest < destsize)
		len_dest++;
	if (destsize <= len_dest)
	{
		return (destsize + len_src);
	}
	i = 0;
	while (src[i] && len_dest + i < destsize - 1)
	{
		dest[len_dest + i] = src[i];
		i++;
	}
	dest[len_dest + i] = '\0';
	return (len_dest + len_src);
}
