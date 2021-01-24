/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armansuy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 13:01:18 by armansuy          #+#    #+#             */
/*   Updated: 2021/01/24 13:43:29 by armansuy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

/*Fonction d'affichage du tableau resolue*/
void	ft_display(char **t)
{
	int i;
	int	j;

	i = 0;
	while (++i < 5)
	{
		j = 0;
		while (++j < 5)
		{
			ft_putchar(t[i][j]);
			if (j != 4)
				ft_putchar(' ');
		}
		ft_putchar('\n');
	}
}
