/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plpelleg <plpelleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 14:08:13 by plpelleg          #+#    #+#             */
/*   Updated: 2021/04/15 17:37:57 by plpelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
This header file contains all macros for errors to be displayed.
*/

#ifndef ERROR_H
# define ERROR_H

# include <stdio.h>

# define END "THE END"
# define FILE_NOT_FOUND "FILE NOT FOUND\n"
# define DOUBLE_PAR "PARAMETER DEFINED TWICE\n"
# define MALLOC_FAIL "FAILED TO ALLOCATE MEMORY\n"
# define NOT_CUB "BAD MAP FILE: FILE EXTENSION IS NOT .cub\n"
# define BAD_PAR "BAD PARAMETER\n"
# define WRONG_PATH "BAD PATH TO TEXTURE GIVEN\n"
# define BAD_RGB "RGB VALUES ENTERED ARE INCORRECT\n"
#endif
