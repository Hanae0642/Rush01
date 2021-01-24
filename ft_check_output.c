/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_output.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armansuy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 07:50:01 by armansuy          #+#    #+#             */
/*   Updated: 2021/01/24 14:00:43 by armansuy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		how_many_in_col(char **t, int col);
int		how_many_in_col_rev(char **t, int col);
int		how_many_in_row(char **t, int row);
int		how_many_in_row_rev(char **t, int row);

/*Fonction qui verifie que le meme chiffre n'est pas deja present sur la 
 * meme ligne ou colonne*/
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

/*Fonction qui appelle 2 sous fonctions qui vont verifier la validite des 
 * chiffres sur une ligne par rapport aux parametres*/
int		valid_row(char **t, int row)
{
	if (!how_many_in_row(t, row) || !how_many_in_row_rev(t, row))
		return (0);
	return (1);
}

/*Fonction qui appelle 2 sous fonctions qui vont verifier la validite des 
 * chiffres sur une colonne par rapport aux parametres*/
int		valid_col(char **t, int col)
{
	if (!how_many_in_col(t, col) || !how_many_in_col_rev(t, col))
		return (0);
	return (1);
}
