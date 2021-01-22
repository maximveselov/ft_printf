/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aannett <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 01:37:57 by aannett           #+#    #+#             */
/*   Updated: 2021/01/22 19:18:31 by aannett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags			*build_flag(void)
{
	flags		ret;

	if (!(ret = malloc(sizeof(t_flags))))
		return (NULL);
	ret.minus = 0;
	ret.zero = 0;
	ret.dot = -1;
	ret.star = 0;
	ret.width = 0;
	ret.is_flag = 0;
	ret->type = 0;
	ret->next = NULL;
	return (ret);
}

int				fill_flag(t_flags **flag, char *ptr)
{
	t_flags		*tmp;
	int			i;

	tmp = build_flag();
	i = 0;
	while (ptr[i])
	{
		if (!flag_check(ptr[i]) && !ft_isdigit(ptr[i]) && !type_check(ptr[i]))
			break ;
		if (ptr[i] == '-')
			tmp.minus = 1;
		i++;
	}
	if (tmp->type)
		tmp.is_flag = 1;
	return (i);
}

t_flags			*parse_flags(const char *str)
{
	t_flags		*head;
	t_flags		*node;
	char		*ptr;
	int			f_size;

	head = build_flag();
	node = head;
	while (*str && (ptr = ft_strchr(str, '%')))
	{
		f_size = fill_flag(&node, ptr);
		str = ptr + f_size;
		node = node->next;
	}
	return (head);
}
