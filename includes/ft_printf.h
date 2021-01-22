/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aannett <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 17:30:31 by aannett           #+#    #+#             */
/*   Updated: 2021/01/22 19:18:32 by aannett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct		s_flags
{
	struct s_list	*next;
	char			type;
	int				is_flag;
	int				minus;
	int				zero;
	int				dot;
	int				star;
	int				width;
}					t_flags;
int					ft_printf(const char *str, ...);
// Struct
t_flags				*build_flag(void);
int					fill_flag(t_flags **flag, char *ptr);
t_flags				*parse_flags(const char *str);
// Strings
void				ft_putchar(char c);
void				ft_putstr(char *str);
// Supplementary functions
int					type_check(char flag);
int					flag_check(char flag);

#endif
