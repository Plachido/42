/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plpelleg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 18:32:14 by plpelleg          #+#    #+#             */
/*   Updated: 2020/12/10 18:32:17 by plpelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int contained(char elem, char *base)
{
	int i;

	i=0;
	while (base[i]!='\0')
	{
		if (base[i] == elem)
			return (1);
		i++;
	}
	return (0);
}

int position(char *elem, char *base)
{
	int i;

	i=0;
	while (base[i]!='\0')
	{
		if (base[i] == elem)
			return (i);
	}
	return (0);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

power(int a, int b)
{
	int i;

	i=0;
	while(i<=b)
	{
			a*=a;
			i++;
	}
}

int     ft_atoi_base(char *str, char *base)
{
	int i;
	int total;
	char clean[ft_strlen(str)];
	int j;
	int neg;

	if()
	i = 0;
	neg = 1;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' ||
	       str[i] == '\f' || str[i] == '\r' || str[i] ==  ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	j = 0;
	while(str[i] != '\0' && contained(str[i], base)==1)
	{
		clean[j] = str[i];
		j++;
		i++;
	}
	while (clean[i] != '\0' && contained(clean[i], base)==1)
	{
		total += power(position(clean[i], base), ft_strlen(base));
	}
	return (total);
}




#include <stdio.h>
#include <string.h>


int main(void)
{
	printf("---Expected-output---\n");
	printf("-2147483648__2147483647__0__69__-42_0_0_0_12_0\n");
	printf("----Actual---output---\n");
	printf("%d__",ft_atoi_base("  +-+-+-cbeiehdgeh123","abcdefgihj"));
	printf("%d__",ft_atoi_base("   ----++--+7FFFFFFFa","0123456789ABCDEF"));
	printf("%d__",ft_atoi_base("++-n","nul"));
	printf("%d__",ft_atoi_base("baf","abcdefgh"));
	printf("%d_",ft_atoi_base("  -+-+-+-+-+--+ahahah","ha"));
	printf("%d_",ft_atoi_base(" +-+-++---+--+xd","asdfghj+qwert"));
	printf("%d_",ft_atoi_base(" -+asdfg","asdfg-hjkl"));
	printf("%d_",ft_atoi_base(" -+-+++-","asdfg hjkl"));
	printf("%d_",ft_atoi_base(" \v-+-+++-asd","asdfghjkdl"));
	printf("%d\n",ft_atoi_base(" -+-+++-","asdfghjkdl"));
	return 0;
}

