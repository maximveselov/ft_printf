/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aannett <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 19:51:03 by aannett           #+#    #+#             */
/*   Updated: 2021/01/26 04:34:30 by aannett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					print_percent(t_flags flag)
{
	int				ret;
	char			c;

	c = flag.zero ? '0' : ' ';
	if (flag.minus)
		c = ' ';
	flag.width -= 1;
	ret = 1;
	if (flag.minus)
		ft_putchar('%');
	while (flag.width-- > 0)
	{
		ft_putchar(c);
		ret++;
	}
	if (!flag.minus)
		ft_putchar('%');
	return (ret);
}
