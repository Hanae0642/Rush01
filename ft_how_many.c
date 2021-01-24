/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_how_many.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armansuy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 08:38:18 by armansuy          #+#    #+#             */
/*   Updated: 2021/01/24 11:30:15 by armansuy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		how_many_in_row(char **t, int row)
{
	char	highest;
	int		how_many;
	int		n;

	how_many = 1;
	highest = t[row][1];
	n = 1;
	while (++n < 5)
	{
		if (highest < t[row][n])
		{
			highest = t[row][n];
			how_many++;
		}
	}
	return (how_many + '0' == t[row][0] ? 1 : 0);
}

int		how_many_in_row_rev(char **t, int row)
{
	char	highest;
	int		how_many;
	int		n;

	how_many = 1;
	highest = t[row][4];
	n = 4;
	while (--n > 0)
	{
		if (highest < t[row][n])
		{
			highest = t[row][n];
			how_many++;
		}
	}
	return (how_many + '0' == t[row][5] ? 1 : 0);
}

int		how_many_in_col(char **t, int col)
{
	char	highest;
	int		how_many;
	int		n;

	how_many = 1;
	highest = t[1][col];
	n = 1;
	while (++n < 5)
	{
		if (highest < t[n][col])
		{
			highest = t[n][col];
			how_many++;
		}
	}
	return (how_many + '0' == t[0][col] ? 1 : 0);
}

int		how_many_in_col_rev(char **t, int col)
{
	char	highest;
	int		how_many;
	int		n;

	how_many = 1;
	highest = t[4][col];
	n = 4;
	while (--n > 0)
	{
		if (highest < t[n][col])
		{
			highest = t[n][col];
			how_many++;
		}
	}
	return (how_many + '0' == t[5][col] ? 1 : 0);
}
