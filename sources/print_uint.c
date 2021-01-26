/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aannett <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 19:44:20 by aannett           #+#    #+#             */
/*   Updated: 2021/01/26 04:35:08 by aannett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int				numlen_unsigned(unsigned int n)
{
	unsigned int		i;

	i = 0;
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	while (n > 0 || n < 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char				*itoa_unsigned(unsigned int n)
{
	char				*r;
	unsigned int		l;
	long				i;

	i = n;
	l = numlen_unsigned(n);
	if (n == 0)
		return (ft_strdup("0"));
	if (!(r = (char*)malloc(sizeof(char) * (l + 1))))
		return (NULL);
	if (i < 0)
	{
		i *= -1;
		r[0] = '-';
	}
	r[l--] = '\0';
	while (i > 0)
	{
		r[l--] = i % 10 + 48;
		i = i / 10;
	}
	return (r);
}

int						print_uint(t_flags flag, unsigned int u)
{
	int					ret;
	char				*uint;

	ret = 0;
	uint = itoa_unsigned(u);
	if (!flag.precision && !u && flag.width)
		ret += ft_putchar(' ');
	if (!flag.precision && u)
	{
		flag.precision = u < 0 ? ft_strlen(uint) - 1 : ft_strlen(uint);
		flag.width += u < 0 ? 1 : 0;
	}
	ret += integer_width(flag, uint);
	free(uint);
	return (ret);
}
