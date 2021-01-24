/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armansuy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 13:18:10 by armansuy          #+#    #+#             */
/*   Updated: 2021/01/24 14:50:56 by armansuy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*Fonction qui libere la memoire alloue au tableau*/
void	ft_free_tab(char **tab)
{
	int	i;

	i = -1;
	while (++i < 6)
	{
		free(tab[i]);
	}
	free(tab);
}
