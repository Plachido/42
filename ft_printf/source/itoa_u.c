/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plpelleg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 13:45:23 by plpelleg          #+#    #+#             */
/*   Updated: 2021/03/04 19:39:21 by plpelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		dig_u(unsigned int n)
{
	int len;

	len = 0;
	while (n >= 1)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char		*special_u(void)
{
	char	*val;

	if (!(val = malloc(1 * sizeof(char) + 1)))
		return (NULL);
	val[0] = '0';
	val[1] = '\0';
	return (val);
}

static char		*add_nul_u(char *str, int idx)
{
	str[idx] = '\0';
	return (str);
}

char			*itoa_u(unsigned int n)
{
	char	*result;
	int		neg;
	int		len;
	int		val;

	neg = 0;
	val = n;
	len = dig_u(n) - 1;
	if (n == 0)
		return (special_u());
	if (!(result = malloc(len + 1 * sizeof(char) + 1)))
		return (NULL);
	while (len >= neg)
	{
		result[len] = (n % 10) + 48;
		n /= 10;
		len--;
	}
	return (add_nul_u(result, dig_u(val)));
}
