/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_hex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plpelleg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 16:39:31 by plpelleg          #+#    #+#             */
/*   Updated: 2021/03/04 19:47:07 by plpelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hash(int flag, t_fields *fields, char *conv)
{
	char	*hash;

	if (*conv != '0')
	{
		if (flag)
			hash = "0X";
		else
			hash = "0x";
		if (fields->hashtag)
		{
			write(1, hash, 2);
			return (2);
		}
	}
	return (0);
}

static int	check_fill_hash(char fill, t_fields *fields, char *conv, int flag)
{
	int	printed;

	printed = 0;
	if (fill == '0')
		printed += hash(flag, fields, conv);
	return (printed);
}

static int	print_x(t_fields *fields, char fill, char *conv, int flag)
{
	int printed;

	if (!(printed = 0) && fields->minus > 0)
	{
		printed += hash(flag, fields, conv);
		while (fields->precision-- > 0 && ++printed)
			write(1, "0", 1);
		while (*conv && ++printed)
			write(1, conv++, 1);
		while (fields->width-- > 0 && ++printed)
			write(1, " ", 1);
	}
	else
	{
		printed = check_fill_hash(fill, fields, conv, flag);
		while (fields->width-- > 0 && ++printed)
			write(1, &fill, 1);
		if (!(fill == '0'))
			printed += hash(flag, fields, conv);
		while (fields->precision-- > 0 && ++printed)
			write(1, "0", 1);
		while (*conv && ++printed)
			write(1, conv++, 1);
	}
	return (printed);
}

int			p_hex(va_list args, t_fields *fields, int flag)
{
	char	*conv;
	int		printed;
	int		len;
	char	fill;

	if ((fill = ' ') && fields->zero && fields->precision == -1)
		fill = '0';
	if (!(conv = hex_conv(va_arg(args, unsigned int), flag)))
		return (-1);
	if (fields->precision == 0 && *conv == '0' && !(fields->hashtag = 0))
		*conv = '\0';
	len = ft_strlen(conv);
	if (len > fields->precision)
		fields->precision = 0;
	else
		fields->precision = fields->precision - len;
	if (fields->width > len + fields->precision)
		fields->width -= (len + fields->precision);
	else
		fields->width = 0;
	if (fields->hashtag && *conv != '0')
		fields->width -= 2;
	printed = print_x(fields, fill, conv, flag);
	free(conv);
	return (printed);
}
