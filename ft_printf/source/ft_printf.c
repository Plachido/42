/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plpelleg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 14:59:25 by plpelleg          #+#    #+#             */
/*   Updated: 2021/03/04 19:38:46 by plpelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	exec(t_fields *fields, va_list args, int *i)
{
	int val;

	if (!(val = 0) && ft_strchr(TYPES, fields->type))
	{
		if (fields->type == 'c')
			val = p_character(args, fields);
		else if (fields->type == 's')
			val = p_string(args, fields);
		else if (fields->type == 'd' || fields->type == 'i')
			val = p_digit(args, fields, 0);
		else if (fields->type == 'u')
			val = p_digit(args, fields, 1);
		else if (fields->type == 'X')
			val = p_hex(args, fields, 1);
		else if (fields->type == 'x')
			val = p_hex(args, fields, 0);
		else if (fields->type == 'p')
			val = p_addr(args, fields);
		else if (fields->type == '%')
			val = p_perc(fields);
	}
	if (val != -1)
		*i += val;
	else
		*i = -1;
}

int		check(t_fields *fields)
{
	if (!ft_strchr(TYPES, fields->type) || !fields->type)
	{
		free(fields);
		return (0);
	}
	return (1);
}

int		elab(va_list args, char *string, int *count)
{
	int			i;
	t_fields	*fields;

	fields = malloc(sizeof(t_fields));
	i = 1;
	init(fields);
	get_flags(&i, string, fields);
	get_width(&i, string, fields, args);
	get_precision(&i, string, fields, args);
	fields->type = string[i];
	if (!(check(fields)))
		return (0);
	if (!(i = 0) && !(fields->type))
		i += 1;
	else
		exec(fields, args, &i);
	if (i == -1)
	{
		free(fields);
		return (0);
	}
	*count += i;
	free(fields);
	return (1);
}

int		ft_printf(const char *format, ...)
{
	int		i;
	va_list	args;
	int		count;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == 37)
		{
			if (!(elab(args, ft_strchr((format + i), 37), &count)))
				return (-1);
			i++;
			while (!ft_strchr(TYPES, format[i]))
				i++;
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
		i++;
	}
	return (count);
}
