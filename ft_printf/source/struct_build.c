/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_build.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plpelleg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 11:04:54 by plpelleg          #+#    #+#             */
/*   Updated: 2021/03/04 19:58:37 by plpelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_flag(char flag, t_fields *fields)
{
	if (flag == '-')
		fields->minus = 1;
	else if (flag == '0')
		fields->zero = 1;
	else if (flag == '#')
		fields->hashtag = 1;
}

void	get_flags(int *i, char *string, t_fields *fields)
{
	while ((ft_strchr(FLAGS, string[*i])) && string[*i] != '\0')
	{
		set_flag(string[*i], fields);
		(*i)++;
	}
}

void	get_width(int *i, char *string, t_fields *fields, va_list args)
{
	int num;

	num = 0;
	if (string[*i] == '*')
	{
		num = va_arg(args, int);
		if (num < 0)
		{
			num = -num;
			fields->minus = 1;
		}
		(*i)++;
	}
	else
		while (ft_isdigit(string[*i]))
			num = (num * 10) + (string[(*i)++] - 48);
	fields->width = num;
}

void	get_precision(int *i, char *string, t_fields *fields, va_list args)
{
	int precision;

	precision = 0;
	if (string[*i] == '.')
	{
		fields->precision = 0;
		(*i)++;
		if (string[*i] == '*')
		{
			precision = va_arg(args, int);
			(*i)++;
		}
		else
			while (ft_isdigit(string[*i]))
				precision = (precision * 10) + (string[(*i)++] - 48);
		if (precision < 0)
			precision = -1;
		fields->precision = precision;
	}
}
