/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aannett <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 19:42:58 by aannett           #+#    #+#             */
/*   Updated: 2021/01/26 04:33:22 by aannett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int						numlen_base_extended(unsigned long long num, int base)
{
	int					i;

	i = 1;
	while (num /= base)
		i++;
	return (i);
}

char					*itoa_base_extended(unsigned long long num, int base)
{
	char				*ret;
	unsigned long long	tmp;
	char				*base_map;
	int					i;

	tmp = num;
	base_map = "0123456789ABCDEF";
	i = numlen_base_extended(num, base);
	if (!(ret = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	ret[i--] = 0;
	while (tmp > 0)
	{
		ret[i] = base_map[tmp % base];
		tmp /= base;
		i--;
	}
	return (ret);
}
