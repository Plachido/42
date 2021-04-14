/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plpelleg <plpelleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 16:57:50 by plpelleg          #+#    #+#             */
/*   Updated: 2021/04/12 19:11:35 by plpelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

/*Checks for the .cub extension*/

static void	ft_check_ext(char *path, t_all *all)
{
	int	len;

	len = ft_strlen(path);
	if (len - 4 < 0)
		len = 0;
	else
		len = len - 4;
	if ((ft_strncmp(path + len, ".cub", 4)))
		ft_error(NOT_CUB, all);
}

/*
Calls all main parsing functions. get_param call is inside get_map because it
returns the last line read, which also is the first map line
*/

void	ft_elab_cub(char *path, t_all *all)
{
	int	fd;

	ft_check_ext(path, all);
	fd = open(path, O_RDONLY);
	//ft_get_param(fd, all);
	ft_get_map(fd, all, ft_get_param(fd, all));
}
