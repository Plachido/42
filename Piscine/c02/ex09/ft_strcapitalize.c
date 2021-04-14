/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plpelleg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 20:25:40 by plpelleg          #+#    #+#             */
/*   Updated: 2020/12/07 14:41:05 by plpelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_strlowcase(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] += 32;
		}
		i++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int i;

	i = 0;
	ft_strlowcase(str);
	while (str[i] != '\0')
	{
		if ((!(str[i - 1] >= 'a' && str[i - 1] <= 'z') &&
		!(str[i - 1] >= 'A' && str[i - 1] <= 'Z') &&
		!(str[i - 1] >= '1' && str[i - 1] <= '9')) || i == 0)
		{
			if (str[i] >= 'a' && str[i] <= 'z')
				str[i] -= 32;
		}
		i++;
	}
	return (str);
}
