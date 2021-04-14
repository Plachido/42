/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_hex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plpelleg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 16:39:31 by plpelleg          #+#    #+#             */
/*   Updated: 2021/03/04 19:53:52 by plpelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_a(t_fields *fields, char fill, char *conv)
{
	int	printed;

	if (!(printed = 0) && fields->minus > 0)
	{
		write(1, "0x", 2);
		printed += 2;
		while (fields->precision-- > 0 && ++printed)
			write(1, "0", 1);
		while (*conv && ++printed)
			write(1, conv++, 1);
		while (fields->width-- > 0 && ++printed)
			write(1, " ", 1);
	}
	else
	{
		while (fields->width-- > 0 && ++printed)
			write(1, &fill, 1);
		write(1, "0x", 2);
		printed += 2;
		while (fields->precision-- > 0 && ++printed)
			write(1, "0", 1);
		while (*conv && ++printed)
			write(1, conv++, 1);
	}
	return (printed);
}

int			p_addr(va_list args, t_fields *fields)
{
	char	*conv;
	int		printed;
	int		len;
	char	fill;

	if ((fill = ' ') && fields->zero && fields->precision == -1)
		fill = '0';
	if (!(conv = itoa_ul(va_arg(args, unsigned long int), "0123456789abcdef")))
		return (-1);
	if (fields->precision == 0 && *conv == '0')
		*conv = '\0';
	len = ft_strlen(conv);
	if (len > fields->precision)
		fields->precision = 0;
	else
		fields->precision = fields->precision - len;
	if (fields->width > len + fields->precision + 2)
		fields->width -= (len + fields->precision + 2);
	else
		fields->width = 0;
	printed = print_a(fields, fill, conv);
	free(conv);
	return (printed);
}
