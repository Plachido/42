/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plpelleg <plpelleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 19:45:48 by plpelleg          #+#    #+#             */
/*   Updated: 2021/04/15 17:37:08 by plpelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

static void ft_check_path(t_all *all)
{
	int fd[4];
	int i;

	i = 0;
	fd[0] = open(all->info->NO,O_RDONLY);
	fd[1] = open(all->info->SO,O_RDONLY);
	fd[2] = open(all->info->EA,O_RDONLY);
	fd[3] = open(all->info->WE,O_RDONLY);
	while (i < 4)
		if (fd[i++] < 0)
			ft_error(WRONG_PATH, all);
	close(fd[0]);
	close(fd[1]);
	close(fd[2]);
	close(fd[3]);
}

static void ft_check_rgb(t_all *all)
{
	int i;

	i = 0;
	while (i <= 3)
		if(!((all->info->F[i] > 255 || all->info->F[i] < 0) ||
		(all->info->C[i] > 255 || all->info->C[i] < 0)))
			ft_error(BAD_RGB, all);
}

//static void ft_check_resolution(t_all *all)
//{
	
//}

void	ft_param_check(t_all *all)
{
	ft_check_path(all);
	ft_check_rgb(all);
	//ft_check_resolution(all);
	
}