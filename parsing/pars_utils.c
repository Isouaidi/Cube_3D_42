/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isouaidi <isouaidi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:01:12 by isouaidi          #+#    #+#             */
/*   Updated: 2024/05/23 18:35:25 by isouaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_exit(char *str)
{
	printf("%s\n", str);
	exit(EXIT_FAILURE);
}

int	tablen(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	inti_var(t_map *map)
{
	map->no = 0;
	map->so = 0;
	map->c = 0;
	map->f = 0;
	map->e = 0;
	map->w = 0;
}

void	print_char_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
	return ;
}

