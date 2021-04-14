/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plpelleg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 11:20:49 by plpelleg          #+#    #+#             */
/*   Updated: 2020/12/11 09:34:11 by plpelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int		check_base(char *base)
{
	int i;
	int j;

	if (ft_strlen(base) <= 1)
		return (0);
	i = 0;
	j = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '-' || base[i] == '+')
			return (0);
		while (base[j] != '\0')
		{
			if (j != i)
			{
				if (base[i] == base[j])
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	printnum(char result[], int i)
{
	while (i >= 0)
	{
		write(1, &result[i], 1);
		i--;
	}
}

int		negfunct(int nbr)
{
	unsigned int number;

	nbr += 1;
	number = -nbr;
	number += 1;
	write(1, "-", 1);
	return (number);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int				base_len;
	char			result[100];
	int				i;
	unsigned int	number;

	base_len = ft_strlen(base);
	if (check_base(base) == 1)
	{
		i = 0;
		if (nbr < 0)
		{
			number = negfunct(nbr);
		}
		else
			number = nbr;
		while (number > 0)
		{
			result[i] = base[number % base_len];
			number /= base_len;
			i++;
		}
		i--;
		printnum(result, i);
	}
}
