/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_elab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plpelleg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 11:26:55 by plpelleg          #+#    #+#             */
/*   Updated: 2021/03/04 19:52:18 by plpelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init(t_fields *fields)
{
	fields->minus = 0;
	fields->zero = 0;
	fields->type = 0;
	fields->width = 0;
	fields->precision = -1;
	fields->hashtag = 0;
}
