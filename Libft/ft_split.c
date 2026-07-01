/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgoulart <rgoulart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 14:50:49 by rgoulart          #+#    #+#             */
/*   Updated: 2026/06/04 21:08:07 by rgoulart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_free_matrix(char **ptr, size_t j)
{
	while (j > 0)
	{
		j--;
		free(ptr[j]);
	}
	free(ptr);
	ptr = NULL;
	return (NULL);
}

static size_t	ft_wordcount(char const *s, char c)
{
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != '\0')
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (count);
}

static void	ft_alocpointer(char **ptr, char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	save;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			save = i;
			while (s[i] != c && s[i])
				i++;
			ptr[j] = ft_substr(s, save, i - save);
			if (ptr[j] == NULL)
			{
				ft_free_matrix(ptr, j);
				return ;
			}
			j++;
		}
	}
	ptr[j] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;

	if (!s)
		return (NULL);
	ptr = (char **)malloc((ft_wordcount(s, c) + 1) * sizeof(char *));
	if (ptr == NULL)
		return (NULL);
	ft_alocpointer(ptr, s, c);
	return (ptr);
}
