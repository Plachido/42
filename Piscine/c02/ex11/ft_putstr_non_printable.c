/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plpelleg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 15:40:35 by plpelleg          #+#    #+#             */
/*   Updated: 2020/12/07 15:43:58 by plpelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_hexa(unsigned char elem)
{
	char c1;
	char c2;

	c1 = "0123456789abcdef"[elem / 16];
	c2 = "0123456789abcdef"[elem % 16];
	write(1, &c1, 1);
	write(1, &c2, 1);
}

int		ft_char_is_printable(char str)
{
	if (!(str >= 32 && str < 127))
	{
		return (0);
	}
	return (1);
}

void	ft_putstr_non_printable(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_char_is_printable(str[i]) == 0)
		{
			write(1, "\\", 1);
			ft_print_hexa(str[i]);
		}
		else
		{
			write(1, &str[i], 1);
		}
		i++;
	}
}
