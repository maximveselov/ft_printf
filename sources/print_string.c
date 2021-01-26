/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aannett <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 19:44:04 by aannett           #+#    #+#             */
/*   Updated: 2021/01/26 04:33:57 by aannett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_string(t_flags flag, const char *str)
{
	int		ret;

	ret = 0;
	str = str ? str : "(null)";
	if (flag.precision > -1 && flag.precision < ft_strlen(str))
		flag.width -= flag.precision;
	else
		flag.width -= ft_strlen(str);
	if (!flag.minus)
	{
		while (flag.width-- > 0)
			ret += ft_putchar(' ');
		ret += putstr_size(str, flag.precision);
	}
	else
	{
		ret += putstr_size(str, flag.precision);
		while (flag.width-- > 0)
			ret += ft_putchar(' ');
	}
	return (ret);
}
