/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plpelleg <plpelleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 16:13:54 by plpelleg          #+#    #+#             */
/*   Updated: 2021/04/07 17:28:43 by plpelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void	ft_init(t_all *all)
{
	t_info	*info;

	ft_bzero(all, sizeof(t_all));
	info = calloc(1, sizeof(*info));
	all->info = info;
}

void	ft_init_array(int *arr, int dim)
{
	int	i;

	i = 0;
	while (i < dim)
	{
		arr[i] = 0;
		i++;
	}
}
