/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armansuy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 08:34:47 by armansuy          #+#    #+#             */
/*   Updated: 2021/01/24 13:48:33 by armansuy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Fonction de verification de l'argument*/
int		ft_check_input(char *str)
{
	int n;

	n = 0;
	while (str[n])
	{
		/*Si str contient autre chose qu'un caractere entre 1 et 4 
		 * aux indexs pairs on retourne 0 :
		 * L'argument est invalide*/
		if (!(n % 2) && (str[n] < '1' || str[n] > '4'))
			return (0);
		/*Si str contient autre chose qu'un espace aux indexs impairs
		 * on retourne 0 : 
		 * L'argument est invalide*/
		else if (n % 2 && str[n] != ' ')
			return (0);
		n++;
	}
	/*Si str a une taille differente de 31 (15 espace + 16 chiffre)
	 * on retourne 0 :
	 * L'argument est invalide
	 * Sinon on retourne 1 :
	 * L'argument est valide*/
	return (n == 31 ? 1 : 0);
}
