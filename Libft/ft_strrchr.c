/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgoulart <rgoulart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 17:56:37 by rgoulart          #+#    #+#             */
/*   Updated: 2026/06/04 21:08:39 by rgoulart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*start;

	start = s;
	while (*s)
	{
		s++;
	}
	while (s > start && (char)*s != (char)c && (char)c != '\0')
	{
		s--;
	}
	if (*s != (char)c)
		return (NULL);
	else
		return ((char *)s);
}
