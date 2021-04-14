/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plpelleg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 15:48:44 by ppunzo            #+#    #+#             */
/*   Updated: 2020/11/28 16:05:01 by ppunzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_character(int m_x, int m_y, int x, int y)
{
	if ((x == 1 && y == 1) || (x == m_x && y == m_y && m_x != 1 && m_y != 1))
	{
		ft_putchar('A');
	}
	else if ((x == m_x && y == 1) || (x == 1 && y == m_y))
	{
		ft_putchar('C');
	}
	else if (y > 1 && y < m_y && x > 1 && x < m_x)
	{
		ft_putchar(' ');
	}
	else
	{
		ft_putchar('B');
	}
}

void	rush(int max_x, int max_y)
{
	int x;
	int y;

	x = 1;
	y = 1;
	if (max_x > 0 && max_y > 0)
	{
		while (y <= max_y)
		{
			while (x <= max_x)
			{
				print_character(max_x, max_y, x, y);
				x++;
			}
			y++;
			x = 1;
			ft_putchar('\n');
		}
	}
}
