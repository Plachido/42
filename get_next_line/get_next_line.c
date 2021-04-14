/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plpelleg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 18:44:35 by plpelleg          #+#    #+#             */
/*   Updated: 2021/03/30 17:07:56 by plpelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*substring(char *string, int begin, char character, int flag)
{
	int		i;
	int		x;
	char	*out;

	i = begin;
	if (((x = 0) == 0) && (int)ft_strlen(string) < begin)
	{
		free(string);
		return (NULL);
	}
	while (string[i] != character && string[i] != '\0')
		i++;
	if (!(out = malloc((i - begin + 1) * sizeof(char))))
		return (NULL);
	i = begin;
	while (string[i] != character && string[i] != '\0')
	{
		out[x] = string[i];
		i++;
		x++;
	}
	out[x] = '\0';
	if (flag == 1)
		free(string);
	return (out);
}

char	*join_free(char *s1, char *s2, int flag)
{
	char	*out;
	int		i;
	int		x;

	i = 0;
	if (!(out = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char))))
		return (NULL);
	if (((x = 0) == 0) && s1)
		while (s1[i] != '\0')
			out[x++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		out[x++] = s2[i++];
	out[x] = '\0';
	free(s1);
	if (flag == 1)
		free(s2);
	return (out);
}

int		check(char **res)
{
	if (!*res)
	{
		if (!(*res = malloc(sizeof(char))))
			return (0);
		*res[0] = '\0';
	}
	return (1);
}

int		elab(int fd, int *reader, char **res, char **line)
{
	char *temp;

	if (!check(res) || !(temp = malloc((BUFFER_SIZE + 1) * sizeof(char))))
		return (-1);
	temp[BUFFER_SIZE] = '\0';
	while (((*reader = read(fd, temp, BUFFER_SIZE)) > 0) &&
			(!(ft_strchr(temp, 10))) && (!(temp[*reader] = '\0')))
		if (!(*res = join_free(*res, temp, 0)))
			return (-1);
	if (*reader < 0)
	{
		free(temp);
		free(*res);
		return (-1);
	}
	temp[*reader] = '\0';
	if (!(*res = join_free(*res, temp, 1)) || ft_strlen(*res) == 0)
	{
		free(*res);
		*line = malloc(sizeof(char));
		**line = '\0';
		return (0);
	}
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static char	*residuals[256];
	char		**res;
	int			reader;
	char		*ptr;
	int			result;

	reader = BUFFER_SIZE;
	if ((result = 1) && (!(line) || BUFFER_SIZE <= 0 || fd > 256 || fd < 0))
		return (-1);
	ptr = residuals[fd];
	if ((res = &ptr) && !(ft_strchr(*res, 10)))
		result = elab(fd, &reader, res, line);
	if (result < 1)
		return (result);
	if (!(*line = substring(*res, 0, '\n', 0)))
		return (-1);
	if ((*res = substring(*res, ft_strlen(*line) + 1, '\0', 1)) &&
			(ft_strlen(*res) == 0))
	{
		free(*res);
		*res = NULL;
	}
	if (((residuals[fd] = *res) || !(residuals[fd])) && reader == 0 && !(*res))
		return (0);
	return (1);
}
