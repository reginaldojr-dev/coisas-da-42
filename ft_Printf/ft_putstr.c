/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgoulart <rgoulart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 08:53:13 by rgoulart          #+#    #+#             */
/*   Updated: 2026/06/26 17:09:47 by rgoulart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	len;

	if (!str)
		str = "(nil)";
	len = 0;
	while (*str)
	{
		len += ft_putchar(*str);
		str++;
	}
	return (len);
}
