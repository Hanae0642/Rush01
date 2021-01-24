/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armansuy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 10:00:53 by armansuy          #+#    #+#             */
/*   Updated: 2021/01/24 07:48:44 by armansuy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	**ft_row_params(char *str, char **t)
{
	int i;
	int n;

	i = 16;
	n = 0;
	while (++n < 5)
	{
		t[n][0] = str[i];
		i += 2;
	}
	n = 0;
	while (++n < 5)
	{
		t[n][5] = str[i];
		i += 2;
	}
	return (t);
}

char	**ft_col_params(char *str, char **t)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (++n < 5)
	{
		t[0][n] = str[i];
		i += 2;
	}
	n = 0;
	while (++n < 5)
	{
		t[5][n] = str[i];
		i += 2;
	}
	t = ft_row_params(str, t);
	return (t);
}

char	**ft_init_tab(char *str)
{
	char	**t;
	int		i;
	int		j;

	if (!(t = malloc(sizeof(char *) * 6)))
		return (0);
	i = 0;
	while (i < 6)
	{
		if (!(t[i] = malloc(sizeof(char) * 6)))
			return (0);
		j = -1;
		while (++j < 6)
			t[i][j] = '0';
		i++;
	}
	t = ft_col_params(str, t);
	return (t);
}
