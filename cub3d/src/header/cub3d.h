/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plpelleg <plpelleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 14:08:06 by plpelleg          #+#    #+#             */
/*   Updated: 2021/04/12 19:30:35 by plpelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <fcntl.h>
# include <stdlib.h>
# include "../../libft/libft.h"

# include "error.h"

typedef struct s_info
{
	int			R[2];
	char		*NO;
	char		*SO;
	char		*WE;
	char		*EA;
	char		*S;
	int			F[3];
	int			C[3];
	char		**map;
}				t_info;

typedef struct s_all
{
	t_info		*info;
}				t_all;

//gnl.c
int				ft_gnl(int fd, char **line, t_all *all);

//cub.c
void			ft_elab_cub(char *path, t_all *all);

//param.c
char			*ft_get_param(int fd, t_all *all);

//array.c
void			ft_set_crf(int RGB[3], char par, t_all *all);

//exit.c
void			ft_error(char *text, t_all *all);

//free.c
void			ft_free_info(t_all *all);

//utils.c
char			*ft_append(char *string, char *app);
void			ft_bad_par(char *string, char *checked, t_all *all);
void			ft_lstrm_last(t_list *list);
char			*ft_copy_free(char *string);
//char			*ft_free_trim_ws(char *string);

//print.c
void			ft_print_all(t_all *all);

//init.c
void			ft_init(t_all *all);
void			ft_init_array(int *arr, int dim);

//map.h
void			ft_get_map(int fd, t_all *all, char *first);

#endif
