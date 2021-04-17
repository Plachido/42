/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plpelleg <plpelleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 16:13:54 by plpelleg          #+#    #+#             */
/*   Updated: 2021/04/17 19:59:15 by plpelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"


void	ft_init(t_all *all)
{
	t_info	*info;
	t_mlx	*mlx;

	info = ft_calloc(1, sizeof(t_info));
	mlx = ft_calloc(1, sizeof(t_mlx));
	if (!info || !mlx)
		ft_error(MALLOC_FAIL, all);
	all->info = info;
	all->mlx = mlx;
}