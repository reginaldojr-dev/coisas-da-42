/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgoulart <rgoulart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 17:53:17 by rgoulart          #+#    #+#             */
/*   Updated: 2026/06/04 21:07:15 by rgoulart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	len_int(long n)
{
	long	len;
	int		i;

	len = n;
	i = 1;
	if (len < 0)
	{
		len *= -1;
		i++;
	}
	while (len >= 10)
	{
		len = (len / 10);
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		i;
	long	j;
	char	*ptr;

	ptr = (char *)malloc((len_int(n) + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	i = len_int(n);
	ptr[i] = '\0';
	j = n;
	if (j < 0)
	{
		j *= -1;
		ptr[0] = '-';
	}
	while (--i != 0)
	{
		ptr[i] = (j % 10) + '0';
		j /= 10;
	}
	if (n >= 0)
		ptr[i] = (j % 10) + '0';
	return (ptr);
}
