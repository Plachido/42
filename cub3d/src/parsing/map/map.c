/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plpelleg <plpelleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 18:24:16 by plpelleg          #+#    #+#             */
/*   Updated: 2021/04/13 19:43:45 by plpelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

/*
Map parsing happens in this file.
*/

static void	ft_map_list(int fd, char *first, t_list **map_lines, t_all *all)
{
	char	*line;
	int		r;

	*map_lines = ft_lstnew(first);
	while (ft_gnl(fd, &line, all))
		ft_lstadd_back(map_lines, ft_lstnew(ft_copy_free(line)));
	ft_lstadd_back(map_lines, ft_lstnew(ft_copy_free(line)));
}

static void ft_empty(void* none){};

void	ft_get_map(int fd, t_all *all, char *first)
{
	t_list	*map_lines;
	t_list	*elem;
	int		i;

	ft_map_list(fd, first, &map_lines, all);
	i = ft_lstsize(map_lines);
	all->info->map = calloc(i, sizeof(char *));
	//calloc all of the char*'s with max map line size
	while (i-- >= 0)
	{
		elem = ft_lstlast(map_lines);
		all->info->map[i] = (char *)elem->content;
		ft_lstrm_last(map_lines);
	}
	free(map_lines);
}
