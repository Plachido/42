/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 18:07:26 by ametta            #+#    #+#             */
/*   Updated: 2020/12/06 18:32:13 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	up_ui(char input[], char col)
{
	char up_val;

	up_val = 0;
	if (col == 1)
		up_val = input[0];
	else if (col == 2)
		up_val = input[1];
	else if (col == 3)
		up_val = input[2];
	else if (col == 4)
		up_val = input[3];
	return (up_val);
}

char	down_ui(char input[], char col)
{
	char down_val;

	down_val = 0;
	if (col == 1)
		down_val = input[4];
	else if (col == 2)
		down_val = input[5];
	else if (col == 3)
		down_val = input[6];
	else if (col == 4)
		down_val = input[7];
	return (down_val);
}

char	right_ui(char input[], char row)
{
	char right_val;

	right_val = 0;
	if (row == 1)
		right_val = input[12];
	else if (row == 2)
		right_val = input[13];
	else if (row == 3)
		right_val = input[14];
	else if (row == 4)
		right_val = input[15];
	return (right_val);
}

char	left_ui(char input[], char row)
{
	char left_val;

	left_val = 0;
	if (row == 1)
		left_val = input[8];
	else if (row == 2)
		left_val = input[9];
	else if (row == 3)
		left_val = input[10];
	else if (row == 4)
		left_val = input[11];
	return (left_val);
}
