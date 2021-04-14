/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush0.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnataliz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 19:01:59 by jnataliz          #+#    #+#             */
/*   Updated: 2020/12/06 20:04:29 by jnataliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_print(char matrix[4][4]);
void	find(int *possib1, int *possib2, int *possib3, int *possib4, char input[]);
char	up_ui(char input[], char col);
char	down_ui(char input[], char col);
char	right(char arr[]);
void	create_perm(char *ptr[]);
char	left(char arr[]);

int		choose_x(int i, int possib[])
{
	int x;

	if (i == 0)
		x = possib[0];
	if (i == 1)
		x = possib[1];
	if (i == 2)
		x = possib[2];
	if (i == 3)
		x = possib[3];
	return (x);
}

int		alldifferent(char matrix[4][4])
{
	int colonna;
	int riga;
	int comp;
	int verify;

	colonna = 0;
	riga = 0;
	comp = 0;
	verify = 1;
	while (colonna <= 3)
	{
		riga = 0;
		while (riga <= 3)
		{
			comp = 0;
			while (comp <= 3)
			{
				if ((matrix[riga][colonna] == matrix[comp][colonna]) &&
						comp != riga)
					verify = 0;
				comp++;
			}
			riga++;
		}
		colonna++;
	}
	return (verify);
}

int		check(int possib1, int possib2, int possib3, int possib4, char input[])
{
	int i;
	char matrix[4][4];
	int j;
	char *permutazioni[24];
	int x;
	create_perm(permutazioni);
	int possibilities[4];

	i = 0;
	possibilities[0] = possib1;
	possibilities[1] = possib2;
	possibilities[2] = possib3;
	possibilities[3] = possib4;
	while (i <= 3)
	{
		j = 0;
		x = choose_x(i, possibilities);
		while (j <= 3)
		{
			matrix[i][j] = permutazioni[x][j];
			j++;
		}
		i++;
	}
	if (alldifferent(matrix) == 1)
	{
		int		z;
		int		ok;
		char	stringa[4];

		z = 1;
		ok = 1;
		i = 0;
		j = 0;
		while (j < 4)
		{
			i = 0;
			while (i < 4)
			{
				stringa[i] = matrix[i][j];
				i++;
			}
			if (!(left(stringa) == up_ui(input, z)))
				ok = 0;
			if (!(right(stringa) == down_ui(input, z)))
				ok = 0;
			j++;
			z++;
		}
		if (ok == 1)
		{
			ft_print(matrix);
			return (1);
		}
	}
	return (0);
}

void	tozero(int *arr[])
{
	arr[0] = 0;
	arr[1] = 0;
	arr[2] = 0;
	arr[3] = 0;
}
