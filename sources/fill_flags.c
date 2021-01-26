/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aannett <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 01:37:57 by aannett           #+#    #+#             */
/*   Updated: 2021/01/26 04:33:34 by aannett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags			build_flag(void)
{
	t_flags		ret;

	ret.minus = 0;
	ret.zero = 0;
	ret.precision = -1;
	ret.star = 0;
	ret.width = 0;
	ret.type = 0;
	return (ret);
}

int				parse_flag(t_flags *flag, const char *ptr, va_list args)
{
	int			i;
	t_flags		tmp;

	i = 1;
	tmp = build_flag();
	while (!tmp.type)
	{
		if (!flag_check(ptr[i]) && !ft_isdigit(ptr[i]) && !type_check(ptr[i]))
			return (0);
		if (ptr[i] == '-' || ptr[i] == '0')
			i += fill_flag(&(ptr[i]), &tmp);
		if (ft_isdigit(ptr[i]) || ptr[i] == '*')
			i += fill_width(&(ptr[i]), &tmp, args);
		if (ptr[i] == '.')
		{
			i += fill_precision(&(ptr[i + 1]), &tmp, args) + 1;
			while (ft_isdigit(ptr[i]))
				i++;
		}
		if (type_check(ptr[i]))
			tmp.type = ptr[i++];
	}
	*flag = tmp;
	return (i);
}
