#include "push_swap.h"

int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r');
}

int	ft_streq(const char *a, const char *b)
{
	int	i;

	i = 0;
	while (a[i] && b[i] && a[i] == b[i])
		i++;
	return (a[i] == '\0' && b[i] == '\0');
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putstr_fd(int fd, const char *s)
{
	write(fd, s, ft_strlen(s));
}

void	ft_putnbr_fd(int fd, long n)
{
	char	buf[24];
	int		i;
	long	x;

	if (n == 0)
		return ((void)write(fd, "0", 1));
	if (n < 0)
		write(fd, "-", 1);
	x = n;
	i = 23;
	buf[i] = '\0';
	while (x != 0)
	{
		if (x < 0)
			buf[--i] = '0' - (x % 10);
		else
			buf[--i] = '0' + (x % 10);
		x /= 10;
	}
	ft_putstr_fd(fd, &buf[i]);
}

void	error_exit(t_input *in)
{
	free_input(in);
	ft_putstr_fd(2, "Error\n");
	exit(1);
}
