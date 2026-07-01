/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft _strmapi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgoulart <rgoulart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 19:43:14 by rgoulart          #+#    #+#             */
/*   Updated: 2026/06/04 21:32:32 by rgoulart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			buffer;
	char			*ptr;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	buffer = ft_strlen(s) + 1;
	ptr = (char *)malloc(buffer * sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	while (s[i])
	{
		ptr[i] = f(i, s[i]);
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
