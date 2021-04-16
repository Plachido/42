/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plpelleg <plpelleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 16:22:41 by plpelleg          #+#    #+#             */
/*   Updated: 2021/04/16 18:33:41 by plpelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

static void	ft_print_info(t_info *info)
{
	int i;
	int j;

	printf("R:	%d, %d\n", info->R[0], info->R[1]);
	printf("NO:	%s\n", info->NO);
	printf("SO:	%s\n", info->SO);
	printf("WE:	%s\n", info->WE);
	printf("EA:	%s\n", info->EA);
	printf("S:	%s\n", info->S);
	printf("F:	%d, %d, %d\n", info->F[0], info->F[1], info->F[1]);
	printf("C:	%d, %d, %d\n", info->C[0], info->C[1], info->C[1]);
	i = 0;
	j = 0;
	while (info->map[j])
		j++;
	while (i < j)
		printf("%s\n", info->map[i++]);
}

void	ft_print_all(t_all *all)
{
	ft_print_info(all->info);
}
