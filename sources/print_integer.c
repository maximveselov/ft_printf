/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aannett <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 19:43:35 by aannett           #+#    #+#             */
/*   Updated: 2021/01/26 04:39:14 by aannett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			num_precision(char *integer, int precision)
{
	int				ret;
	int				diff;

	ret = 0;
	diff = precision - ft_strlen(integer);
	if (!precision)
		return (ret);
	if (*integer == '-')
	{
		ret += ft_putchar('-');
		integer++;
		diff++;
	}
	while (diff-- > 0)
		ret += ft_putchar('0');
	ret += putstr_size(integer, -1);
	return (ret);
}

static int			print_num(t_flags flag, char *s)
{
	int				ret;
	char			c;

	ret = 0;
	if (flag.precision <= -1)
		c = flag.zero ? '0' : ' ';
	else
		c = ' ';
	flag.width -= flag.precision > ft_strlen(s) ? flag.precision : ft_strlen(s);
	if (c == ' ' && *s == '-' && flag.precision < ft_strlen(s) - 1
		&& flag.precision != -1)
		flag.width += 1;
	if ((c == '0' && *s == '-') || (*s == '-' && flag.precision != -1))
	{
		ret += (c == '0') ? ft_putchar('-') : 0;
		s += (c == '0') ? 1 : 0;
		flag.width -= (c == '0') ? 0 : 1;
	}
	while (flag.width-- > 0)
		ret += ft_putchar(c);
	if (flag.precision)
		ret += num_precision(s, flag.precision);
	return (ret);
}

int					integer_width(t_flags flag, char *integer)
{
	int				ret;
	int				diff;

	ret = 0;
	diff = flag.width;
	diff -= flag.precision > ft_strlen(integer) ? flag.precision
	: ft_strlen(integer);
	if (*integer == '-' && flag.precision != -1
		&& flag.precision > ft_strlen(integer))
		diff -= 1;
	if (flag.minus)
	{
		ret += num_precision(integer, flag.precision);
		while (diff-- > 0)
		{
			ft_putchar(' ');
			ret++;
		}
	}
	else
		ret += print_num(flag, integer);
	return (ret);
}

int					print_integer(t_flags flag, int d)
{
	int				ret;
	char			*integer;

	ret = 0;
	integer = ft_itoa(d);
	if (!flag.precision && !d && flag.width)
		ret += ft_putchar(' ');
	if ((flag.type == 'd' || flag.type == 'i') && !flag.precision && d)
	{
		flag.precision = d < 0 ? ft_strlen(integer) - 1 : ft_strlen(integer);
		flag.width += d < 0 ? 1 : 0;
	}
	ret += integer_width(flag, integer);
	free(integer);
	return (ret);
}
