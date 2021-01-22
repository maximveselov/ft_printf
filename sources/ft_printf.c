/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aannett <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 18:20:18 by aannett           #+#    #+#             */
/*   Updated: 2021/01/22 06:14:56 by aannett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				parse_input(const char *str, va_list args)
{
	int			i;
	flags		structure;

	i = 0;
	while (str[i])
	{
		structure = build_flag();

	}
}

int				ft_printf(const char *str, ...)
{
	va_list		args;
	int			ret;
	
	va_start(args, str);
	ret = parse_input(str, args);

	va_end(args);
	return (ret);
}
