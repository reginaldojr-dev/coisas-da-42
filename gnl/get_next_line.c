/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifreire <ifreire@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 00:13:17 by rgoulart          #+#    #+#             */
/*   Updated: 2026/07/10 12:51:59 by ifreire          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*fill_stash(int fd, char *stash, char *buf, size_t from)
{
	char	*tmp;
	int		bytes;

	bytes = read(fd, buf, BUFFER_SIZE);
	while (bytes > 0)
	{
		buf[bytes] = '\0';
		tmp = ft_strjoin(stash, buf);
		if (!tmp)
			return (NULL);
		stash = tmp;
		if (ft_strchr(stash + from, '\n'))
			break ;
		from += bytes;
		bytes = read(fd, buf, BUFFER_SIZE);
	}
	if (bytes == -1)
	{
		free(stash);
		return (NULL);
	}
	return (stash);
}

static char	*read_to_stash(int fd, char *stash)
{
	char	*buffer;
	size_t	from;

	if (stash && ft_strchr(stash, '\n'))
		return (stash);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	from = 0;
	if (stash)
		from = ft_strlen(stash);
	stash = fill_stash(fd, stash, buffer, from);
	free(buffer);
	return (stash);
}

static char	*extract_line(char *stash)
{
	int		i;
	char	*line;

	if (!stash || stash[0] == '\0')
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	line = ft_substr(stash, 0, i);
	return (line);
}

static char	*clean_stash(char *stash)
{
	char	*new_stash;
	int		i;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i] || stash[i + 1] == '\0')
	{
		free(stash);
		return (NULL);
	}
	new_stash = ft_strdup(stash + i + 1);
	free(stash);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_to_stash(fd, stash);
	if (!stash || !*stash)
	{
		free(stash);
		return (NULL);
	}
	line = extract_line(stash);
	stash = clean_stash(stash);
	return (line);
}
