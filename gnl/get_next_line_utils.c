/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgoulart <rgoulart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 00:13:39 by rgoulart          #+#    #+#             */
/*   Updated: 2026/07/11 06:56:48 by rgoulart         ###   ########.fr       */
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
	size_t	stash_len;
	size_t	i;
	size_t	j;
	char	*ptr;

	stash_len = 0;
	if (stash)
		stash_len = ft_strlen(stash);
	ptr = malloc(stash_len + ft_strlen(buffer) + 1);
	if (!ptr)
		return (free(stash), NULL);
	i = 0;
	while (i < stash_len)
	{
		ptr[i] = stash[i];
		i++;
	}
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
	if (start >= len_stash)
		result = 0;
	else
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

	if (!stash)
		return (NULL);
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
