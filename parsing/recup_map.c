/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isouaidi <isouaidi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 19:14:38 by isouaidi          #+#    #+#             */
/*   Updated: 2024/05/21 19:51:56 by isouaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

bool	is_map(char *s)
{
	int	i;
	int	f;

	f = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '1' || s[i] == ' ' || s[i] == '\n')
			f++;
		else
			return (false);
	}
	return (true);
}

int	countmap(char **tab)
{
	int	i;
	int	count;
	int	f;

	f = 0;
	count = 0;
	i = 0;
	while (tab[i])
	{
		if (is_map(tab[i]) == true && f == 0)
			f = 1;
		if (f == 1)
			count++;
		i++;
	}
	printf("%d", count);
	return (count);
}

void	recup_map(t_map *map)
{
	int	i;
	int	j;
	int	f;
	int	count;

	count = countmap(map->file);
	map->map = malloc(sizeof(char *) * count + 1);
	f = 0;
	i = 0;
	j = 0;
	while (map->file[i])
	{
		if (is_map(map->file[i]) == true && f == 0)
		{
			map->map[j] = ft_strdup(map->file[i]);
			j++;
			f = 1;
		}
		if (f == 1)
			map->map[j++] = ft_strdup(map->file[i]);
		i++;
	}
	map->map[j] = NULL;
}
