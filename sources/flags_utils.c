/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aannett <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 17:39:30 by aannett           #+#    #+#             */
/*   Updated: 2021/01/26 04:16:27 by aannett          ###   ########.fr       */
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

int			fill_flag(const char *ptr, t_flags *flag)
{
	if (*ptr == '-')
		(*flag).minus = 1;
	else if (*ptr == '0')
		(*flag).zero = 1;
	return (1);
}

int			fill_width(const char *ptr, t_flags *flag, va_list args)
{
	int		ret;

	if (*ptr == '*')
	{
		(*flag).width = va_arg(args, int);
		ret = 1;
	}
	else
	{
		(*flag).width = ft_atoi(ptr);
		ret = 0;
		while (ft_isdigit(ptr[ret]))
			ret++;
	}
	if ((*flag).width < 0)
	{
		(*flag).minus = 1;
		(*flag).width *= -1;
	}
	return (ret);
}

int			fill_precision(const char *ptr, t_flags *flag, va_list args)
{
	if (!ft_isdigit((int)*ptr) && *ptr != '*')
	{
		(*flag).precision = 0;
		return (0);
	}
	if (*ptr == '*')
	{
		(*flag).precision = va_arg(args, int);
		return (1);
	}
	else
	{
		(*flag).precision = ft_atoi(ptr);
		return (ft_strlen(ft_itoa((*flag).precision)));
	}
}
