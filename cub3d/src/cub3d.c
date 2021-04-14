/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plpelleg <plpelleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 14:07:16 by plpelleg          #+#    #+#             */
/*   Updated: 2021/04/13 19:16:26 by plpelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		ft_elab_cub(argv[1], all);
		ft_print_all(all);
	}
	ft_error(END, all);
}
