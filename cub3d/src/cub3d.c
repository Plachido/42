/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plpelleg <plpelleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 14:07:16 by plpelleg          #+#    #+#             */
/*   Updated: 2021/04/14 19:46:28 by plpelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
main function. Steps:	1)Create and initialize t_all type variable
			2)Parse .cub file
			...
			n)End the program
			
*/

#include "header/cub3d.h"

int	main(int argc, char **argv)
{
	t_all	*all;

	all = calloc(1, sizeof(t_all));
	if (!all)
	{
		printf(MALLOC_FAIL);
		exit(0);
	}
	if (argc >= 2)
	{
		ft_init(all);
		//all->mlx->mlx_ptr = mlx_init();
		ft_elab_cub(argv[1], all);
		ft_print_all(all);
	}
	ft_error(END, all);
}
