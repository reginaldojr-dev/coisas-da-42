/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgoulart <rgoulart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 00:13:39 by rgoulart          #+#    #+#             */
/*   Updated: 2026/07/09 02:37:26 by rgoulart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	index;

	index = 0;
	while (s[index] != '\0')
		index++;
	return (index);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != (char)c)
	{
		s++;
	}
	if (*s != (char)c)
		return (NULL);
	else
		return ((char *)s);
}

char	*ft_strjoin(char *stash, char *buffer)
{
	size_t	j;
	int		i;
	char	*ptr;

	if (!stash)
	{
		stash = (char *)malloc(1);
		if (!stash)
			return (NULL);
		stash[0] = '\0';
	}
	ptr = (char *)malloc(ft_strlen(stash) + ft_strlen(buffer) + 1);
	if (!ptr)
		return (free(stash), NULL);
	i = -1;
	while (stash[++i])
		ptr[i] = stash[i];
	j = 0;
	while (buffer[j])
		ptr[i++] = buffer[j++];
	ptr[i] = '\0';
	free(stash);
	return (ptr);
}

char	*ft_substr(const char *stash, unsigned int start, size_t len)
{
	unsigned int	len_stash;
	unsigned int	result;
	char			*ptr;
	size_t			i;

	len_stash = ft_strlen(stash);
	result = len_stash - start;
	if (len < result)
		result = len;
	ptr = (char *)malloc((result + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < result)
	{
		ptr[i] = stash[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strdup(char *stash)
{
	size_t	len;
	size_t	i;
	char	*ptr;

	len = 0;
	while (stash[len])
		len++;
	ptr = (char *)malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	while (stash[i])
	{
		ptr[i] = stash[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
