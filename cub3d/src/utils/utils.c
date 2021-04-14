/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plpelleg <plpelleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 17:34:28 by plpelleg          #+#    #+#             */
/*   Updated: 2021/04/12 19:30:24 by plpelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

/*
This file containes useful functions of various types.
*/

/*
The following function returns the parameter defined string trimmed of eventual
whitespaces at the beginning or at the end. The original string is freed.


char	*ft_free_trim_ws(char *string)
{
	char	*tmp;

	tmp = ft_substr(string, 0, ft_strlen(string));
	free(string);
	string = ft_strtrim(tmp, " ");
	free(tmp);
	return (string);
}*/

/*
This function joins two strings, and frees only the first one passed.
*/

char	*ft_append(char *string, char *app)
{
	char	*ret;

	ret = ft_strjoin(string, app);
	free(string);
	return (ret);
}

void	ft_bad_par(char *string, char *checked, t_all *all)
{
	free(string);
	free(checked);
	checked = NULL;
	ft_error(BAD_PAR, all);
}

void	ft_lstrm_last(t_list *list)
{
	int i;
	int j;
	t_list *elem;

	i = 1;
	j = ft_lstsize(list);
	while (i++ < j - 1)
		list = list->next;
	elem = list->next;
	list->next = NULL;
	free(elem);
}

char *ft_copy_free(char *string)
{
	char *res;
	int len;

	len = ft_strlen(string) + 2;
	res = calloc(len, sizeof(char));
	ft_strlcpy(res, string, len);
	free(string);
	return(res);
}