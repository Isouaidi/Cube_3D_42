/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isouaidi <isouaidi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:01:12 by isouaidi          #+#    #+#             */
/*   Updated: 2024/05/24 15:58:41 by isouaidi         ###   ########.fr       */
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

void	free_all(t_map *map)
{
	free(map->int_c);
	free(map->int_f);
	free_tab(map->file);
	free_tab(map->text);
	free_tab(map->map);
	free_tab(map->colors);
	free(map->c_col);
	free(map->f_col);
}
