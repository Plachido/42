/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plpelleg <plpelleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 18:21:06 by plpelleg          #+#    #+#             */
/*   Updated: 2021/04/07 18:47:28 by plpelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

/*
The following function manages the storing of values
contained in the integer array created in ft_parse_crf (param.c file)
to the correct field of the 'info' variable, inside the main
t_all type variable.
*/

void	ft_set_crf(int arr[3], char par, t_all *all)
{
	if (par == 'C')
	{
		all->info->C[0] = arr[0];
		all->info->C[1] = arr[1];
		all->info->C[2] = arr[2];
	}
	if (par == 'R')
	{
		all->info->R[0] = arr[0];
		all->info->R[1] = arr[1];
	}
	if (par == 'F')
	{
		all->info->F[0] = arr[0];
		all->info->F[1] = arr[1];
		all->info->F[2] = arr[2];
	}
}

/*


void	ft_call_set_crf(int arr[3], char crf, t_all *all)
{
	if (crf == 'C')
		ft_set_crf(arr, 'C', all);
	if (crf == 'R')
		ft_set_crf(arr, 'R', all);
	if (crf == 'F')
		ft_set_crf(arr, 'F', all);
}

*/
