/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plpelleg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 09:09:00 by plpelleg          #+#    #+#             */
/*   Updated: 2020/12/11 09:18:12 by plpelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		get_tot(char *str, int i, int mem, int mult)
{
	int total;

	total = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (i != mem)
			mult *= 10;
		i++;
	}
	i = mem;
	while (str[i] >= '0' && str[i] <= '9')
	{
		total += (str[i] - 48) * mult;
		mult /= 10;
		i++;
	}
	return (total);
}

int		ft_atoi(char *str)
{
	int			i;
	int			neg;
	int			mem;
	int			total;
	long int	mult;

	i = 0;
	mult = 1;
	neg = 1;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' ||
			str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	mem = i;
	total = get_tot(str, i, mem, mult);
	return (total * neg);
}
