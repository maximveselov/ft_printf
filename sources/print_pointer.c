/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aannett <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 19:43:48 by aannett           #+#    #+#             */
/*   Updated: 2021/01/26 04:35:28 by aannett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			pointer_width(t_flags flag, char *str)
{
	int				ret;
	int				diff;

	ret = 0;
	if (str[ret] == '0' && !flag.precision && ft_strlen(str) == 1)
		str = "";
	diff = flag.width - (ft_strlen(str) + 2);
	if (flag.minus)
	{
		ret += putstr_size("0x", -1);
		ret += putstr_size(str, -1);
	}
	while (diff-- > 0)
	{
		ft_putchar(' ');
		ret++;
	}
	if (!flag.minus)
	{
		ret += putstr_size("0x", -1);
		ret += putstr_size(str, -1);
	}
	return (ret);
}

int					print_pointer(t_flags flag, unsigned long long ptr)
{
	char			*print;
	int				ret;

	ret = 0;
	if (!ptr)
		return (pointer_width(flag, "0"));
	print = tolower_str((itoa_base_extended(ptr, 16)));
	if (!flag.precision && ptr)
		flag.precision = ft_strlen(print);
	ret += pointer_width(flag, print);
	free(print);
	return (ret);
}
