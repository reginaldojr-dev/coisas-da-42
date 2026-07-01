/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgoulart <rgoulart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 14:53:49 by rgoulart          #+#    #+#             */
/*   Updated: 2026/06/04 21:57:45 by rgoulart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	start;
	size_t	end;
	char	*ptr;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (ft_strchr(set, s1[start]) != NULL && s1[start])
	{
		start++;
	}
	if (s1[start] == '\0')
	{
		ptr = ft_strdup("");
		return (ptr);
	}
	end = ft_strlen(s1);
	while (ft_strchr(set, s1[end - 1]) != NULL)
		end--;
	ptr = (char *)malloc((end - start + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	ft_strlcpy(ptr, &s1[start], (end - start) + 1);
	return (ptr);
}
