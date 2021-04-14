/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_digit2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plpelleg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 12:09:23 by plpelleg          #+#    #+#             */
/*   Updated: 2021/03/04 19:56:10 by plpelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	free_cond(long int passed, t_fields *fields, char **conv)
{
	if (passed != 2147483648 && !(passed == 0 && fields->precision >= 0) &&
			passed != 4294967295)
		free(*conv);
}

int		neg_print(int neg, char to_print, int *printed)
{
	int	val;

	if (neg && to_print == ' ')
		write(1, "-", 1);
	if ((val = 0) == 0 && (neg))
		(*printed)++;
	return (val);
}
