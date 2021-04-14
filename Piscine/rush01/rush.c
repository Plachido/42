/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 18:01:05 by ametta            #+#    #+#             */
/*   Updated: 2020/12/06 18:33:44 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	up_ui(char input[], char col);
char	down_ui(char input[], char col);
char	right_ui(char input[], char row);
char	left_ui(char input[], char row);

void	fill_array(char *tofill[]);
void	create_perm(char *ptr[]);

char	left(char arr[])
{
	int		i;
	char	max;
	int		count;
	char	left;

	i = 0;
	max = '0';
	count = 0;
	while (arr[i] != '\0')
	{
		if ((arr[i] > arr[i - 1] && arr[i] > max) || (i == 0))
		{
			count += 1;
			if (max < arr[i])
				max = arr[i];
		}
		i++;
	}
	left = count + '0';
	return (left);
}

char	right(char arr[])
{
	int		i;
	char	max;
	int		count;
	char	right;

	i = 3;
	max = '0';
	count = 0;
	while (i >= 0)
	{
		if ((arr[i] > arr[i + 1] && arr[i] > max) || (i == 3))
		{
			count += 1;
			if (max < arr[i])
				max = arr[i];
		}
		i--;
	}
	right = count + '0';
	return (right);
}

void	input_parser(char arg[], char parsed[])
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (arg[i] != '\0')
	{
		if (i % 2 == 0)
		{
			parsed[j] = arg[i];
			j++;
		}
		i++;
	}
}

void	get_possible(int row, int *result, char input[])
{
	int		i;
	int		j;
	char	left_val;
	char	right_val;
	char	*permutazioni[24];

	right_val = right_ui(input, row);
	left_val = left_ui(input, row);
	i = 0;
	j = 0;
	create_perm(permutazioni);
	while (i < 24)
	{
		if (left(permutazioni[i]) == left_val &&
				right(permutazioni[i]) == right_val)
		{
			result[j] = i;
			j++;
		}
		i++;
	}
}
