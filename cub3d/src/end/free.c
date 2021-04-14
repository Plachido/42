/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plpelleg <plpelleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 16:54:25 by plpelleg          #+#    #+#             */
/*   Updated: 2021/04/13 19:25:56 by plpelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

/*All following functions free a specific function*/

void	ft_free_info(t_all *all)
{
	t_info	*info;
	int i;

	i = 0;
	info = all->info;
	if (info->NO)
		free(info->NO);
	if (info->SO)
		free(info->SO);
	if (info->WE)
		free(info->WE);
	if (info->EA)
		free(info->EA);
	if (info->S)
		free(info->S);
	while (info->map[i])
	{
		free(info->map[i]);
		info->map[i++] = NULL;
		if (!info->map[i])
			free(info->map);
	}
	if (info)
		free(info);
}
