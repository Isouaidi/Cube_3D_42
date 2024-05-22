/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isouaidi <isouaidi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:52:41 by isouaidi          #+#    #+#             */
/*   Updated: 2024/05/22 20:07:16 by isouaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	last_space(t_map *map, size_t *count)
{
	int i;
	
	i = 0;
	while (map->map[i + 1])
	{
		if (i == 0)
		{
			if(ft_strlen(map->map[i]) > ft_strlen(map->map[i + 1]))
				(*count) = ft_strlen(map->map[i]);
			else
				(*count) = ft_strlen(map->map[i + 1]);
		}
		else
		{
			if ((*count) < ft_strlen(map->map[i + 1]))
				(*count) = ft_strlen(map->map[i + 1]);
		}
		i++;
	}
	// printf("%ld\n\n", (*count));
}
void	first_sapce(t_map *map)
{
	int i;
	int j; 
	size_t count;

	i = 0;
	while (map->map[i])
	{
		map->map[i] = ft_strjoin(" ", map->map[i]);
		map->map[i] = ft_strjoin(map->map[i], " ");
		i++;
	}
	last_space(map, &count);
	// printf("2  = %ld\n", (count));
	i = 0;
	while (map->map[i])
	{
		j = ft_strlen(map->map[i]);
		while (j <= (int)count)
		{
			map->map[i] = ft_strjoin(map->map[i], " ");
			j++;
		}
		i++;
	}
	print_char_tab(map->map);
}
int	check_char(char *str, int *n, int *w, int *s)
{
	int i;
	int e;

	e = 0;
	i = 0;
	while (str[i])
	{
		if(!(str[i] == '1' || str[i] == '0' || str[i] == 'N' 
			|| str[i] == 'W' || str[i] == 'E' || str[i] == 'S' || str[i] == ' '))
				ft_exit("Error\nMap take only 1,0,W,S,N,E");
		if(str[i] == 'E')
			e++;
		if(str[i] == 'N')
			(*n)++;
		if(str[i] == 'S')
			(*s)++;
		if(str[i] == 'W')
			(*w)++;
		i++;
	}
	return (e);
}


void check_all_map(t_map *map, int n, int w, int s)
{
	int i;
	int e;

	e = 0;
	i = 0;
	while (map->map[i])
	{
		e += check_char(map->map[i], &n,&w,&s);
		i++;
	}
	if (e+n+w+s != 1)
		ft_exit("Error\n Cube take 1 player");
}
