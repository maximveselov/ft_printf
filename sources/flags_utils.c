/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aannett <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 17:39:30 by aannett           #+#    #+#             */
/*   Updated: 2021/01/22 19:04:53 by aannett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			type_check(char flag)
{
	if (flag == 'c' || flag == 's' || flag == 'p' || flag == 'd' || flag == 'i'
		|| flag == 'u' || flag == 'x' || flag == 'X' || flag == '%')
		return (1);
	else
		return (0);
}

int			flag_check(char flag)
{
	if (flag == '-' || flag == '.' || flag == '*')
		return (1);
	else
		return (0);
}
