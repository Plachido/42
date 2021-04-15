/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plpelleg <plpelleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 18:24:16 by plpelleg          #+#    #+#             */
/*   Updated: 2021/04/15 18:38:16 by plpelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

/*
Map parsing happens in this file.
*/

/*
This function populates a list with the rows of the .cub file indicating the map.
Technically, each row becomes the 'content' element of the t_list object.
When the end of line is read, the last row gets too but would be excluded from the
loop: this is why at the end, the same code written inside the loop is repeated
once.
*/

static void	ft_map_list(int fd, char *first, t_list **map_lines, t_all *all)
{
	char	*line;

	*map_lines = ft_lstnew(first);
	while (ft_gnl(fd, &line, all))
		ft_lstadd_back(map_lines, ft_lstnew(ft_copy_free(line)));
	ft_lstadd_back(map_lines, ft_lstnew(ft_copy_free(line)));
}

/*
This is the main map parsing function. Here a list is created, in order to know
what size the matrix containing the map should be. After having populated that
list with the use of ft_map_list, all parsed strings containing the map are put
inside the matrix. The list is freed at the end of the function.
*/

void	ft_get_map(int fd, t_all *all, char *first)
{
	t_list	*map_lines;
	t_list	*elem;
	int		i;

	ft_map_list(fd, first, &map_lines, all);
	i = ft_lstsize(map_lines);
	all->info->map = ft_calloc(i, sizeof(char *));
	while (i-- > 0)
	{
		elem = ft_lstlast(map_lines);
		all->info->map[i] = (char *)elem->content;
		ft_lstrm_last(map_lines);
	}
	free(map_lines);
}
