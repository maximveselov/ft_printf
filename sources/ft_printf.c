/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aannett <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 18:20:18 by aannett           #+#    #+#             */
/*   Updated: 2021/01/26 04:34:16 by aannett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				print_arg(t_flags flag, va_list args)
{
	if (!flag.type)
		return (0);
	else if (flag.type == 'c')
		return (print_char(flag, va_arg(args, int)));
	else if (flag.type == 's')
		return (print_string(flag, va_arg(args, char*)));
	else if (flag.type == 'p')
		return (print_pointer(flag, va_arg(args, unsigned long long)));
	else if (flag.type == 'd' || flag.type == 'i')
		return (print_integer(flag, va_arg(args, int)));
	else if (flag.type == 'u')
		return (print_uint(flag, va_arg(args, unsigned int)));
	else if (flag.type == 'x' || flag.type == 'X')
		return (print_hexademical(flag, va_arg(args, unsigned int)));
	else if (flag.type == '%')
		return (print_percent(flag));
	return (0);
}

int				print_result(const char *str, va_list args)
{
	int			i;
	int			ret;
	t_flags		flag;

	ret = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i += parse_flag(&flag, &(str[i]), args);
			ret += print_arg(flag, args);
		}
		else
		{
			ft_putchar(str[i]);
			i++;
			ret++;
		}
	}
	return (ret);
}

int				ft_printf(const char *str, ...)
{
	va_list		args;
	int			ret;

	va_start(args, str);
	ret = print_result(str, args);
	va_end(args);
	return (ret);
}
