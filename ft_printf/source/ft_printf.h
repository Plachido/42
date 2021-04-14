/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plpelleg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 12:01:26 by plpelleg          #+#    #+#             */
/*   Updated: 2021/03/04 19:36:20 by plpelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

# define TYPES "cspdiuxX%"
# define FLAGS "-0#"

typedef struct		s_fields
{
	int				minus;
	int				zero;
	int				type;
	int				width;
	int				precision;
	int				hashtag;
}					t_fields;

int					ft_printf(const char *format, ...);
int					elab(va_list args, char *string, int *count);

void				init(t_fields *fields);
void				set_flag(char flag, t_fields *fields);
void				get_flags(int *i, char *string, t_fields *fields);
void				get_width(int *i, char *string, t_fields *fields,
		va_list args);
void				get_precision(int *i, char *string, t_fields *fields,
		va_list args);

int					p_character(va_list args, t_fields *fields);
int					p_string(va_list args, t_fields *fields);
int					p_digit(va_list args, t_fields *fields, int flag);
int					p_hex(va_list args, t_fields *fields, int flag);
int					p_addr(va_list args, t_fields *fields);
int					p_perc(t_fields *fields);

void				free_cond(long int passed, t_fields *fields, char **conv);
int					neg_print(int neg, char to_print, int *printed);
void				print(t_fields *fields);

char				*hex_conv(unsigned int num, int flag);
char				*itoa_u(unsigned int n);
char				*itoa_ul(unsigned long int n, char *base);

#endif
