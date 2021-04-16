/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plpelleg <plpelleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 16:13:54 by plpelleg          #+#    #+#             */
/*   Updated: 2021/04/16 17:55:14 by plpelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"


void	ft_init(t_all *all)
{
	t_info	*info;
	t_mlx	*mlx;

	info = ft_calloc(1, sizeof(t_info));
//	ft_bzero(info, sizeof(t_info));
	mlx = ft_calloc(1, sizeof(t_mlx));
//	ft_bzero(mlx, sizeof(t_mlx));
	all->info = info;
	all->mlx = mlx;
}


/*
void	ft_init_array(int *arr, int dim)
{
	int	i;

	i = 0;
	while (i < dim)
		arr[i++] = 0;
}
*/