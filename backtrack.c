/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armansuy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 07:30:21 by armansuy          #+#    #+#             */
/*   Updated: 2021/01/24 10:27:11 by armansuy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		check_rc(char **t, int row, int col, char c);
int		valid_col(char **t, int col);
int		valid_row(char **t, int row);
void	ft_display(char **t);

int		finish(char **t, int row)
{
	if (row == 5)
	{
		ft_display(t);
		return (1);
	}
	return (0);
}

int		backtrack(char **t, int row, int col, char c)
{
	if (finish(t, row))
		return (1);
	while (++c <= '4')
	{
		t[row][col] = c;
		if (col < 4 && row < 4 && check_rc(t, row, col, c) &&
				backtrack(t, row, col + 1, '0'))
			return (1);
		else if (col == 4 && check_rc(t, row, col, c) && valid_row(t, row))
		{
			if (row == 4 && check_rc(t, row, col, c) && valid_col(t, col) &&
					backtrack(t, row + 1, col, '0'))
				return (1);
			else if (row != 4 && check_rc(t, row, col, c) &&
					backtrack(t, row + 1, 1, '0'))
				return (1);
		}
		else if (row == 4 && col != 4 && check_rc(t, row, col, c) &&
				valid_col(t, col) && backtrack(t, row, col + 1, '0'))
			return (1);
	}
	t[row][col] = '0';
	return (0);
}
