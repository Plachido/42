/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plpelleg <plpelleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 18:48:57 by plpelleg          #+#    #+#             */
/*   Updated: 2021/04/17 19:56:58 by plpelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

/*
In this file, parsing of parameters happens. Functions get called in order from
last to first.
*/

/*
This function manages parsing of a string containing values inside
an integer array. The values either refer to RGB colors ('C' and 'F'
parameters), or to the resolution of the screen ('R' parameter).
After the values have been stored, they get stored in the static array
inside the 'info' fields of the 'all' variable by calling ft_set_crf.
Finally, the integer array is freed, since its existence is no longer
necessary because the values are available inside the 'all' variable.
*/

static void	ft_parse_crf(char *string, t_all *all, char crf)
{
	int		i;
	int		col;
	int		*arr;
	char	delim;

	i = 0;
	col = 0;
	delim = ',';
	if (crf == 'R')
		delim = ' ';
	arr = ft_calloc(3, sizeof(int));
	if (!arr)
	{
		free(string);
		ft_error(MALLOC_FAIL, all);
	}
	while (i++ <= (int)ft_strlen(string) && col++)
		while (string[i] != '\0' && string[i] != delim)
			arr[col] = (arr[col] * 10) + (string[i++] - 48);
	ft_set_crf(arr, crf, all);
	free(arr);
}

/*
When a wall texture parameter is found, the following functions puts it inside 
the right fields of the 'all' variable (in particular, inside the 'info' field),
if it has not been found before. If it has been found before (which means the
value of the pointer is not NULL), an error is displayed with ft_error. At the
end of the function, the string read by gnl is freed.
*/

static void	ft_assign_card(t_all *all, char par, char *string)
{
	char *sub;
	char *arg;
	
	sub = ft_substr(string, 3, ft_strlen(string) - 3);
	arg = ft_strtrim(sub, " ");
	free(sub);
	if ((par == 'N') && !(all->info->NO))
		all->info->NO = arg;
	else if ((par == 'S') && !(all->info->SO))
		all->info->SO = arg;
	else if ((par == 'W') && !(all->info->WE))
		all->info->WE = arg;
	else if ((par == 'E') && !(all->info->EA))
		all->info->EA = arg;
	else
	{
		free(string);
		free(arg);
		ft_error(DOUBLE_PAR, all);
	}
	free(string);
}

/*
This function only is called from ft_get_other, and has been crated mainly
in order to respect the norme. Here the assignation function ft_parse_crf is
called for 'C', 'R' and F parameters and the actual assignation of the 'S'
parameter can happen.
The function proceeds with assignation for all parameters only if they have
not been set before. If they have, an error message is displayed by using
ft_error. At the very end of the function, the parameter added to the 'all'
variable is saved inside the 'checked' string.
*/

static void	ft_assign_crsf(t_all *all, char par, char *string, char *checked)
{
	char *sub;

	sub = ft_strtrim(string + 1, " ");
	free(string);
	if ((par == 'C') && !(ft_strchr(checked, 'C')))
		ft_parse_crf(sub, all, 'C');
	else if ((par == 'R') && !(ft_strchr(checked, 'R')))
		ft_parse_crf(sub, all, 'R');
	else if ((par == 'S') && !(ft_strchr(checked, 'S')))
		all->info->S = sub;
	else if ((par == 'F') && !(ft_strchr(checked, 'F')))
		ft_parse_crf(sub, all, 'F');
	else
	{
		free(sub);
		ft_error(DOUBLE_PAR, all);
	}
	if (par != 'S')
		free(sub);
	checked[ft_strlen(checked)] = par;
}

/*
This function is called if the string read from the .cub is not a wall
texture. This means it either is a bad typed parameter, a 'S', 'R', 'C' or 'F'
parameter, the beginning of the map or an empty line.
Each time a allowed parameter is found, it is added to the 'checked' string.
If a correct parameter is found, function ft_assign_crsf gets called, if
an empty line is found (which is made by checking the lenght of 'checked' at
the beginning and at the end of the function) nothing is done, and if a bad
bad character (neither a parameter nor a 1 indicating the beginning of the map)
is found both the gnl-parsed string and the 'checked' variables get freed
(and checked is set to point to NULL) and a specific error string is passed to
ft_error, which will manage both the deallocation of all structures inside
all, all and will proceed with ending the program.
At the beginning, a copy of the string trimmed of all whitespaces at its beginning
and its end is created. If the first character of that new variable is '1', the
first line of the map has been read, and the parameter parsing has come to its end.
*/

static int	ft_get_other(char *string, char *checked, t_all *all)
{
	int	len;
	char *trimmed;
	char first;

	trimmed = ft_strtrim(string, " ");
	first = trimmed[0];
	free(trimmed);
	len = ft_strlen(checked);
	if (first == '1')
		return(0);
	if (string[0] == 'C' && string[1] == ' ')
		ft_assign_crsf(all, 'C', string, checked);
	else if (string[0] == 'R' && string[1] == ' ')
		ft_assign_crsf(all, 'R', string, checked);
	else if (string[0] == 'S' && string[1] == ' ')
		ft_assign_crsf(all, 'S', string, checked);
	else if (string[0] == 'F' && string[1] == ' ')
		ft_assign_crsf(all, 'F', string, checked);
	else if (ft_strlen(string))
		ft_bad_par(BAD_PAR, string, checked, all);
	else if ((len == (int)ft_strlen(checked)) && (string[0] != '\0'))
		ft_bad_par(DOUBLE_PAR, string, checked, all);
	return (1);
}

/*
Main parameter parsing function. 'checked' variable keeps track of whether
parameters 'S' 'R' 'C' and 'F' have already been read. For the other
parameters, this check is made by checking if the variable inside the
structure still is NULL. This is made because it makes it easier to check
if the static integer array is uninitialized. For 'S', the basic approach
of checking for NULL could have been adopted, but has been avoided since
the 'S', 'R', 'C' and 'F' parameters get parsed together in order to respect
the norme and using the same approach inside the function makes code easier
to understand. After allocating 'checked', each line of the file is read
(until the first line of the map which gets returned), and the 'all' variable
(in particular the 'info' field) gets populated by calling ft_assign_card
when a wall texture path is passed and ft_get_other in all other cases.
*/

char	*ft_get_param(int fd, t_all *all)
{
	char	*string;
	char	*checked;

	checked = ft_calloc(5, sizeof(char));
	if (!checked)
		ft_error(MALLOC_FAIL, all);
	while (ft_gnl(fd, &string, all))
	{
		if (string[0] == 'N' && string[1] == 'O' && string[2] == ' ')
			ft_assign_card(all, 'N', string);
		else if (string[0] == 'S' && string[1] == 'O' && string[2] == ' ')
			ft_assign_card(all, 'S', string);
		else if (string[0] == 'W' && string[1] == 'E' && string[2] == ' ')
			ft_assign_card(all, 'W', string);
		else if (string[0] == 'E' && string[1] == 'A' && string[2] == ' ')
			ft_assign_card(all, 'E', string);
		else if (!(ft_get_other(string, checked, all)))
			break ;
	}
	free (checked);
	return (string);
}
