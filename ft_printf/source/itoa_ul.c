/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plpelleg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 13:45:23 by plpelleg          #+#    #+#             */
/*   Updated: 2021/03/04 19:53:43 by plpelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_iultoa_unary(unsigned long int n, char *base)
{
	char	*p;

	if ((p = ft_calloc(n + 1, sizeof(*p))))
	{
		while (n)
			p[--n] = *base;
	}
	return (p);
}

static size_t	count_digits_b(unsigned long int n, size_t len_b)
{
	size_t num;

	num = 0;
	if (!n)
		num = 1;
	while (n)
	{
		n = n / len_b;
		num++;
	}
	return (num);
}

static void		convert(unsigned long int n, char *p, size_t digits, char *base)
{
	size_t	len_b;

	len_b = ft_strlen(base);
	if (!n)
		*p = base[n];
	while (n)
	{
		p[digits - 1] = base[n % len_b];
		n = n / len_b;
		digits--;
	}
}

char			*itoa_ul(unsigned long int n, char *base)
{
	char		*p;
	size_t		digits;
	size_t		len_b;

	p = NULL;
	if (base && *base)
	{
		len_b = ft_strlen(base);
		if (len_b > 1)
		{
			digits = count_digits_b(n, len_b);
			if ((p = ft_calloc(digits + 1, sizeof(*p))))
				convert(n, p, digits, base);
		}
		else
			p = ft_iultoa_unary(n, base);
	}
	return (p);
}
