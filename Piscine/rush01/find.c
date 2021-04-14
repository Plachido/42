/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnataliz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 19:56:14 by jnataliz          #+#    #+#             */
/*   Updated: 2020/12/06 20:01:04 by jnataliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		check(int possib1, int possib2, int possib3, int possib4, char input[]);
void	tozero(int *arr[]);

void	find(int *possib1, int *possib2, int *possib3, int *possib4, char input[])
{
	int arr[4];
	int control;

	tozero((int **)arr);
	while ((possib1[arr[0]] > possib1[arr[0] - 1] &&
				possib1[arr[0]] <= 23) || arr[0] == 0)
	{
		arr[1] = 0;
		while ((possib2[arr[1]] > possib2[arr[1] - 1] &&
					possib2[arr[1]] <= 23) || arr[1] == 0)
		{
			arr[2] = 0;
			while ((possib3[arr[2]] > possib3[arr[2] - 1] &&
						possib3[arr[2]] <= 23) || arr[2] == 0)
			{
				arr[3] = 0;
				while ((possib4[arr[3]] > possib4[arr[3] - 1] &&
							possib4[arr[3]] <= 23) || arr[3] == 0)
				{
					control = check(possib1[arr[0]], possib2[arr[1]],
							possib3[arr[2]], possib4[arr[3]], input);
					if (control == 1)
					{
						if (control == 1)
							return ;
					}
					arr[3]++;
				}
				arr[2]++;
			}
			arr[1]++;
		}
		arr[0]++;
	}
}
