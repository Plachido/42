/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plpelleg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 08:37:49 by plpelleg          #+#    #+#             */
/*   Updated: 2020/12/01 08:43:27 by plpelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_num(int number)
{
	char num_arr[2];

	num_arr[1] = number % 10 + '0';
	num_arr[0] = (number / 10) % 10 + '0';
	write(1, &num_arr, 2);
}

void	ft_print_comb2(void)
{
	int num1;
	int num2;

	num1 = 0;
	num2 = 0;
	while (num1 != 99 && num2 != 100)
	{
		while (num1 <= 99)
		{
			num2 = num1 + 1;
			while (num2 <= 99)
			{
				if (num1 != num2)
				{
					print_num(num1);
					write(1, " ", 1);
					print_num(num2);
				}
				if (num1 != 98 || num2 != 99)
					write(1, ", ", 2);
				num2++;
			}
			num1++;
		}
	}
}
