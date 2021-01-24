/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armansuy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 07:30:21 by armansuy          #+#    #+#             */
/*   Updated: 2021/01/24 14:41:12 by armansuy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		check_rc(char **t, int row, int col, char c);
int		valid_col(char **t, int col);
int		valid_row(char **t, int row);
void	ft_display(char **t);

/*Fonction qui verifie si le tableau est resolue et affiche
 * le tableau si c'est le cas*/
int		finish(char **t, int row)
{
	if (row == 5)
	{
		ft_display(t);
		return (1);
	}
	return (0);
}

/*Fonction recursive qui tente de resoudre le tableau en essayant chaque caractere a 
 * chaque index*/
int		backtrack(char **t, int row, int col, char c)
{
	if (finish(t, row))
		return (1);
	/*On boucle sur les caracteres entre 1 et 4*/
	while (++c <= '4')
	{
		t[row][col] = c;
		/*Si on est ni sur la derniere colonne ni sur la derniere ligne et que le caracetere
		 * n'est pas deja sur la meme colonne et la meme ligne on rappelle notre fonction en
		 * incrementant notre index colonne et en reinitialisant notre compteur de caractere*/
		if (col < 4 && row < 4 && check_rc(t, row, col, c) &&
				backtrack(t, row, col + 1, '0'))
			return (1);
		/*Sinon si on est sur la derniere colonne et que le caractere n'est pas deja present sur la
		 * meme ligne et la meme colonne et que les caracteres presents sur la ligne respecte
		 * les conditions des parametres*/
		else if (col == 4 && check_rc(t, row, col, c) && valid_row(t, row))
		{
			/*Si on est sur la derniere ligne et que les parametres sont valides, notre tableau est
			 * complet on rappelle notre fonction avec row = 5*/
			if (row == 4 && check_rc(t, row, col, c) && valid_col(t, col) &&
					backtrack(t, row + 1, col, '0'))
				return (1);
			/*Sinon si on est pas sur la derniere ligne et et que les parametres sont valides on
			 * rappelle notre fonction pour la ligne suivante et on reinitialise l'index ligne et 
			 * le caractere*/
			else if (row != 4 && check_rc(t, row, col, c) &&
					backtrack(t, row + 1, 1, '0'))
				return (1);
		}
		/*Sinon si on est sur la derniere ligne mais pas sur la derniere colonne et que les parametres
		 * sont valides on rappelle notre fonction en incrementant la colonne et en reinitialisant le 
		 * caractere*/
		else if (row == 4 && col != 4 && check_rc(t, row, col, c) &&
				valid_col(t, col) && backtrack(t, row, col + 1, '0'))
			return (1);
	}
	t[row][col] = '0';
	/*Si aucune solution est trouvee on retourne 0*/
	return (0);
}
