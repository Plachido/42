/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plpelleg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 12:21:12 by plpelleg          #+#    #+#             */
/*   Updated: 2021/02/18 14:54:09 by plpelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

char		*ft_strchr(const char *s, int c);
size_t		ft_strlen(const char *s);
int			get_next_line(int fd, char **line);
int			check(char **res);
int			elab(int fd, int *reader, char **res, char **line);
char		*join_free(char *s1, char *s2, int flag);
char		*substring(char *string, int begin, char character, int flag);

#endif
