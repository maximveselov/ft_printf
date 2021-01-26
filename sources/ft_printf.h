/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aannett <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 17:30:31 by aannett           #+#    #+#             */
/*   Updated: 2021/01/26 04:32:43 by aannett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "../libft/libft.h"

typedef struct		s_flags
{
	char			type;
	int				is_flag;
	int				minus;
	int				zero;
	int				precision;
	int				star;
	int				width;
}					t_flags;
int					ft_printf(const char *str, ...);
t_flags				build_flag(void);
int					fill_flag(const char *ptr, t_flags *flag);
int					fill_width(const char *ptr, t_flags *flag, va_list args);
int					fill_precision(const char *ptr, t_flags *flag,
va_list args);
int					parse_flag(t_flags *flag, const char *ptr, va_list args);
int					print_result(const char *str, va_list args);
int					print_arg(t_flags flag, va_list args);
int					print_char(t_flags flag, int c);
int					print_string(t_flags flag, const char *str);
int					print_pointer(t_flags flag, unsigned long long ptr);
int					print_integer(t_flags flag, int d);
int					print_uint(t_flags flag, unsigned int u);
int					print_hexademical(t_flags flag, unsigned int x);
int					print_percent(t_flags flag);
int					integer_width(t_flags flag, char *integer);
int					ft_putchar(char c);
int					putstr_size(const char *str, int size);
char				*tolower_str(char *str);
int					numlen_base_extended(unsigned long long num, int base);
char				*itoa_base_extended(unsigned long long num, int base);
int					type_check(char flag);
int					flag_check(char flag);

#endif
