/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aannett <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 21:34:38 by aannett           #+#    #+#             */
/*   Updated: 2021/01/24 22:53:23 by aannett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_char(t_flags flag, int c)
{
	int		ret;

	ret = 1;
	flag.width -= 1;
	if (flag.minus)
		ft_putchar(c);
	while (flag.width-- > 0)
	{
		ft_putchar(' ');
		ret++;
	}
	if (!flag.minus)
		ft_putchar(c);
	return (ret);
}
