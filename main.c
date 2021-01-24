/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armansuy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 08:24:50 by armansuy          #+#    #+#             */
/*   Updated: 2021/01/24 13:39:27 by armansuy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Prototypes des fonctions necessaires au fonctionnement du main*/
void	ft_putstr(char *str);
void	ft_display(char **t);
void	ft_free_tab(char **t);
int		ft_check_input(char *str);
char	**ft_init_tab(char *str);
int		backtrack(char **t, int row, int col, char c);

int		main(int ac, char **av)
{
	char	**t;

	/*Si le nb d'argument est different de 2 ou si l'argument est invalide :
	 * On affiche un message d'erreur et on quitte le programme*/
	if (ac != 2 || !ft_check_input(av[1]))
	{
		ft_putstr("Error\n");
		return (0);
	}
	/*Initialisation du tableau*/
	t = ft_init_tab(av[1]);
	/*Si la fonction backtracking ne trouve pas de solution :
	 * On affiche un message d'erreur*/
	if (!backtrack(t, 1, 1, '0'))
		ft_putstr("Error\n");
	/*On libere la memoire allouee au tableau*/
	ft_free_tab(t);
	return (0);
}
