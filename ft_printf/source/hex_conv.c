/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_conv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plpelleg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 16:42:09 by plpelleg          #+#    #+#             */
/*   Updated: 2021/03/04 19:53:33 by plpelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	hex_val(int num, int flag)
{
	if (num < 10)
		return (num + 48);
	else
	{
		if (flag)
			return (num + 55);
		else
			return (num + 87);
	}
}

char		*hex_conv(unsigned int num, int flag)
{
	char			*conv;
	int				size;
	unsigned int	n;

	n = num;
	size = 0;
	if (num == 0)
		size++;
	while (n > 0 && ++size)
		n /= 16;
	if (!(conv = malloc((size + 1) * sizeof(char))))
		return (NULL);
	conv[size] = '\0';
	while (size > 0)
	{
		conv[size - 1] = hex_val(num % 16, flag);
		num /= 16;
		size--;
	}
	return (conv);
}
