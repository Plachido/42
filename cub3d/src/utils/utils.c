/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plpelleg <plpelleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 17:34:28 by plpelleg          #+#    #+#             */
/*   Updated: 2021/04/17 20:00:00 by plpelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

/*
This file containes useful functions of various types.
*/

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

/* Frees the correct variables, in the eventuality a bad parameter is found.
These frees could not be included inside ft_error, since it does take only
the structure and the error message as parameters.
*/

void	ft_bad_par(char *error, char *string, char *checked, t_all *all)
{
	free(string);
	free(checked);
	checked = NULL;
	ft_error(error, all);
}

/* Removes the last elements of a t_list. */

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

/* Copies a string and returns it. The original is freed. */
char *ft_copy_free(char *string)
{
	char *res;
	int len;

	len = ft_strlen(string) + 1;
	res = ft_calloc(len, sizeof(char));
	if (!res)
		
	ft_strlcpy(res, string, len);
	free(string);
	return(res);
}