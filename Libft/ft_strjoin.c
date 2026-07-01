/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgoulart <rgoulart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 13:54:15 by rgoulart          #+#    #+#             */
/*   Updated: 2026/06/04 21:08:22 by rgoulart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	buffer_size;
	char	*ptr;

	if (!s1 || !s2)
		return (NULL);
	buffer_size = ft_strlen(s1) + ft_strlen(s2) + 1;
	ptr = (char *)malloc(buffer_size * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	ft_strlcpy(ptr, s1, buffer_size);
	ft_strlcat(ptr, s2, buffer_size);
	return (ptr);
}
