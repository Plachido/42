/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_string.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plpelleg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 17:42:21 by plpelleg          #+#    #+#             */
/*   Updated: 2021/03/04 19:52:06 by plpelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		p_string_pt3(t_fields *fields, char *passed, int printed[2],
		char to_print)
{
	int	i;

	i = 0;
	while (passed[i] != '\0' && ((printed[1] < fields->precision) ||
				fields->precision == -1))
	{
		write(1, &passed[i++], 1);
		printed[0]++;
		printed[1]++;
	}
	if ((fields->minus) && (fields->width > printed[0]))
		while ((printed[0] < fields->width))
		{
			write(1, &to_print, 1);
			printed[0]++;
		}
	return (printed[0]);
}

int				p_string_pt2(t_fields *fields, char *passed, int printed[2],
		char to_print)
{
	int	val;

	if ((!(fields->minus)) && (fields->width > (int)ft_strlen(passed) ||
				(fields->width > fields->precision && fields->precision > -1)))
	{
		val = fields->precision;
		if (fields->precision == -1)
			fields->precision = 0;
		while ((printed[0] + (int)ft_strlen(passed) < fields->width) ||
				((printed[0] + fields->precision < fields->width)
				&& (val > -1)))
		{
			write(1, &to_print, 1);
			printed[0]++;
		}
		fields->precision = val;
	}
	return (p_string_pt3(fields, passed, printed, to_print));
}

int				p_string(va_list args, t_fields *fields)
{
	int		printed[2];
	char	*passed;
	char	to_print;

	printed[0] = 0;
	printed[1] = 0;
	to_print = ' ';
	if (fields->zero && !fields->minus)
		to_print = '0';
	passed = va_arg(args, char*);
	if (!passed)
		passed = "(null)";
	return (p_string_pt2(fields, passed, printed, to_print));
}
