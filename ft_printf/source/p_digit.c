/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_digit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plpelleg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 11:05:57 by plpelleg          #+#    #+#             */
/*   Updated: 2021/03/04 19:44:48 by plpelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			get_val(t_fields *fields, char **conv)
{
	int val;

	val = fields->precision;
	if (val == -1)
		val = 0;
	if (val > 0)
	{
		if (val > (int)ft_strlen(*conv))
			val -= (int)(ft_strlen(*conv));
		else
			val = 0;
	}
	return (val);
}

char		*get_conv(t_fields *fields, long int passed, int *neg)
{
	char	*conv;

	if (passed == 2147483648)
		conv = "2147483648";
	else if (passed == 4294967295)
		conv = "4294967295";
	else if (passed > 2147483648)
		conv = itoa_u(passed);
	else if (!passed && fields->precision >= 0)
		conv = "";
	else
		conv = ft_itoa(passed);
	if (*conv == '0')
		*neg = 0;
	return (conv);
}

int			p_width_precision(t_fields *fields, char *conv, int neg,
		char to_print)
{
	int val;
	int printed;

	printed = 0;
	val = get_val(fields, &conv);
	while ((!fields->minus && fields->width >
			(val + ((int)ft_strlen(conv) + neg) + printed)))
	{
		write(1, &to_print, 1);
		printed++;
	}
	val = neg_print(neg, to_print, &printed);
	while (fields->precision > -1 && val++ <
			fields->precision - ((int)ft_strlen(conv)))
	{
		write(1, "0", 1);
		printed++;
	}
	val = -1;
	while (++val < (int)ft_strlen(conv))
	{
		write(1, &conv[val], 1);
		printed++;
	}
	return (printed);
}

long int	get_passed(va_list args, int flag)
{
	long int passed;

	if (flag == 0)
		passed = va_arg(args, int);
	else
		passed = va_arg(args, long int);
	return (passed);
}

int			p_digit(va_list args, t_fields *fields, int flag)
{
	int			printed;
	long int	passed;
	int			neg_val[2];
	char		to_print;
	char		*conv;

	neg_val[0] = 0;
	printed = 0;
	if ((to_print = ' ') && fields->zero && fields->precision == -1)
		to_print = '0';
	passed = get_passed(args, flag);
	if ((neg_val[1] = fields->precision || !neg_val[1]) && (passed < 0) &&
			(neg_val[0] = 1))
		passed *= -1;
	conv = get_conv(fields, passed, &neg_val[0]);
	if (neg_val[0] && to_print == '0')
		write(1, "-", 1);
	printed = p_width_precision(fields, conv, neg_val[0], to_print);
	while ((fields->minus) && printed < fields->width)
	{
		write(1, " ", 1);
		printed++;
	}
	free_cond(passed, fields, &conv);
	return (printed);
}
