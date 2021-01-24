/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_output.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armansuy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 07:50:01 by armansuy          #+#    #+#             */
/*   Updated: 2021/01/24 10:26:40 by armansuy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		how_many_in_col(char **t, int col);
int		how_many_in_col_rev(char **t, int col);
int		how_many_in_row(char **t, int row);
int		how_many_in_row_rev(char **t, int row);

int		check_rc(char **t, int row, int col, char c)
{
	int i;
	int j;

	i = row;
	j = col;
	while (--j > 0)
		if (c == t[row][j])
			return (0);
	while (--i > 0)
		if (c == t[i][col])
			return (0);
	return (1);
}

int		valid_row(char **t, int row)
{
	if (!how_many_in_row(t, row) || !how_many_in_row_rev(t, row))
		return (0);
	return (1);
}

int		valid_col(char **t, int col)
{
	if (!how_many_in_col(t, col) || !how_many_in_col_rev(t, col))
		return (0);
	return (1);
}
