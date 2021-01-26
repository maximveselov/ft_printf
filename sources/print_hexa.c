/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aannett <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 19:43:21 by aannett           #+#    #+#             */
/*   Updated: 2021/01/26 04:31:54 by aannett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					print_hexademical(t_flags flag, unsigned int x)
{
	int				ret;
	char			*hexa;

	ret = 0;
	if (x)
		hexa = itoa_base_extended((unsigned long long)x, 16);
	else
		hexa = ft_strdup("0");
	if (flag.type == 'x')
		hexa = tolower_str(hexa);
	if (!flag.precision && !x && flag.width)
		ret += ft_putchar(' ');
	if (!flag.precision && x)
	{
		flag.precision = x < 0 ? ft_strlen(hexa) - 1 : ft_strlen(hexa);
		flag.width -= x > 0 ? 0 : 1;
	}
	ret += integer_width(flag, hexa);
	free(hexa);
	return (ret);
}
