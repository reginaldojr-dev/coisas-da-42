#include "push_swap.h"

static int	grow_line(char **line, int *cap, int len)
{
	char	*new_line;
	int		i;

	if (len + 2 < *cap)
		return (1);
	new_line = malloc(sizeof(char) * (*cap * 2));
	if (!new_line)
		return (0);
	i = 0;
	while (i < len)
	{
		new_line[i] = (*line)[i];
		i++;
	}
	free(*line);
	*line = new_line;
	*cap *= 2;
	return (1);
}

static int	init_line(char **line, int *cap)
{
	*cap = 32;
	*line = malloc(sizeof(char) * *cap);
	return (*line != NULL);
}

int	checker_read_line(char **line)
{
	char	c;
	int		len;
	int		cap;
	int		ret;

	if (!init_line(line, &cap))
		return (-1);
	len = 0;
	ret = read(0, &c, 1);
	while (ret > 0)
	{
		if (!grow_line(line, &cap, len))
			return (free(*line), -1);
		(*line)[len++] = c;
		if (c == '\n')
			break ;
		ret = read(0, &c, 1);
	}
	if (ret < 0 || (ret == 0 && len == 0))
		return (free(*line), ret);
	(*line)[len] = '\0';
	return (len);
}
