/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plpelleg <plpelleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 16:44:15 by plpelleg          #+#    #+#             */
/*   Updated: 2021/04/15 18:12:25 by plpelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Short version of get_next_line, with buffer size set to one. The main idea is
that every character is read and appended to the string which has to get filled.
If the character is \n 1 is returned, if the EOF has been reached 0 is returned,
else -1 is returned (error).
*/

#include "../header/cub3d.h"

static char	*ft_charjoin(char *s, char c, int max, t_all *all)
{
	char	*ret;
	int		i;

	i = -1;
	ret = malloc(max + 2);
	if (!ret)
		ft_error(MALLOC_FAIL, all);
	while (s[++i])
		ret[i] = s[i];
	ret[i++] = c;
	ret[i] = '\0';
	free(s);
	return (ret);
}

int	ft_gnl(int fd, char **line, t_all *all)
{
	char	c;
	int		i;
	int		max;

	i = 0;
	max = 0;
	if (line == 0)
		return (-1);
	*line = malloc(1);
	*line[0] = 0;
	i = read(fd, &c, 1);
	while (i > 0)
	{
		if (c == '\n')
			break ;
		*line = ft_charjoin(*line, c, max++, all);
		i = read(fd, &c, 1);
	}
	if (i == -1)
		return (-1);
	if (i)
		return (1);
	return (0);
}
