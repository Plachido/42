/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plpelleg <plpelleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 16:13:54 by plpelleg          #+#    #+#             */
/*   Updated: 2021/04/14 19:44:26 by plpelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

static void	ft_init_info(t_info *info)
{
	info->SO = NULL;
	info->WE = NULL;
	info->EA = NULL;
	info->NO = NULL;
	info->S = NULL;
}

/*
This function initializes the t_all type variable, by creating and pointing
the elements it contains.
*/

void	ft_init(t_all *all)
{
	t_info	*info;
	t_mlx	*mlx;

	info = calloc(1, sizeof(t_info*));
	ft_init_info(info);
	mlx = calloc(1, sizeof(t_mlx*));
	all->info = info;
}

/*
FORSE TRASCURABILE CON CALLOC
*/

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
