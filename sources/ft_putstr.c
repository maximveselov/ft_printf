/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aannett <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 20:09:40 by aannett           #+#    #+#             */
/*   Updated: 2021/01/26 04:31:31 by aannett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int			putstr_size(const char *str, int size)
{
	int		i;

	i = 0;
	if (size >= 0)
	{
		while (i < size && str[i])
			ft_putchar(str[i++]);
	}
	else
	{
		while (str[i])
			ft_putchar(str[i++]);
	}
	return (i);
}
