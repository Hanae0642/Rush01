/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armansuy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 08:24:50 by armansuy          #+#    #+#             */
/*   Updated: 2021/01/24 10:38:58 by armansuy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putstr(char *str);
void	ft_display(char **t);
void	ft_free_tab(char **t);
int		ft_check_input(char *str);
char	**ft_init_tab(char *str);
int		backtrack(char **t, int row, int col, char c);

int		main(int ac, char **av)
{
	char	**t;

	if (ac != 2 || !ft_check_input(av[1]))
	{
		ft_putstr("Error\n");
		return (0);
	}
	t = ft_init_tab(av[1]);
	if (!backtrack(t, 1, 1, '0'))
		ft_putstr("Error\n");
	ft_free_tab(t);
	return (0);
}
