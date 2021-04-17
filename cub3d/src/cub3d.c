/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plpelleg <plpelleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 14:07:16 by plpelleg          #+#    #+#             */
/*   Updated: 2021/04/17 17:54:36 by plpelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
main function. Steps:	1) Create and initialize t_all* type variable
			2) Parse .cub file
			...
			n) End the program
			
*/

#include "header/cub3d.h"

int	main(int argc, char **argv)
{
	t_all	*all;

	all = malloc(sizeof(t_all));
	if (!all)
	{
		printf(MALLOC_FAIL);
		return(0);
	}
	if (argc >= 2)
	{
		ft_init(all);
		ft_elab_cub(argv[1], all);
		ft_print_all(all);
	}
	ft_error(END, all);
}
