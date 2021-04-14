/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_perc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plpelleg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 17:20:08 by plpelleg          #+#    #+#             */
/*   Updated: 2021/03/04 19:56:58 by plpelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		p_perc(t_fields *fields)
{
	char	to_print;
	char	passed;
	int		printed;

	printed = 0;
	to_print = ' ';
	if (fields->zero && !fields->minus)
		to_print = '0';
	if (!fields->minus && fields->width)
		while (fields->width-- > 1)
		{
			write(1, &to_print, 1);
			printed++;
		}
	passed = '%';
	write(1, &passed, 1);
	printed++;
	if (fields->minus && fields->width)
		while (fields->width-- > 1 && printed++)
			write(1, &to_print, 1);
	return (printed);
}
