/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isouaidi <isouaidi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:59:07 by isouaidi          #+#    #+#             */
/*   Updated: 2024/05/19 22:09:01 by isouaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

bool	is_colors(char *s, t_map *map)
{
	if (s[0] == 'F' && s[1] == ' ' && (s[2] >= '0' &&  s[2] <= '9'))
	{
		map->f ++;	
		return (true);
	}
	else if (s[0] == 'C' &&  s[1] == ' ' && (s[2] >= '0' &&  s[2] <= '9'))
	{
		map->c ++;	
		return (true);
	}
	else
		return (false);
}
bool	count_colors(t_map *map)
{
	if (map->c == 1 && map->f == 1)
		return(true);
	else
		return(false);
}

void	check_colors(t_map *map)
{
	int i;
	int j;
	int count; 
	
	map->colors = malloc(sizeof(char *) * 2);
	i = 0;
	j = 0;
	count = 0;
	while (map->file[i])
	{
		map->file[i] = without_space(map->file[i]);
		if (is_colors(map->file[i], map) == true)
		{
			if (count == 2)
				ft_exit(TOO_MUCH_TEXTURES);
			map->colors[j] = ft_strdup(map->file[i]);
			j++;
			count++;
		}
		i++;
	}
	map->colors[j] = NULL;
	if (count_colors(map) == false)
		ft_exit("Error\nCheck your colors");
	print_char_tab(map->colors);	
}
// char	*without_space_count(char *s, t_map *map)
// {
// 	int	i;

// 	map->cont_int = 0;
// 	i = 0;
// 	while (s[i] == ' ' && s[i] == '\t')
// 	{
// 		i++;
// 		map->cont_int ++;
// 	}
// 	return (s + i);
// }
// bool	is_f(char *s)
// {
// 	if (s[0] == 'F' && (s[1] == ' ' || s[1] == '\t'))
// 		return (true);
// 	else
// 		return (false);
// }

void	tab_col(t_map *map, int i, int j, int d)
{
	while (map->colors[i])
	{
		d = 0;
		j = 2;
		if (map->colors[i][j - 2] == 'F')
		{
			map->f_col = malloc(sizeof(char) * ft_strlen(map->colors[i]) - 1);
			while (map->colors[i][j])
				map->f_col[d++] = map->colors[i][j++];
			map->f_col[d] = '\0';	
		}
		else if (map->colors[i][j - 2] == 'C')
		{
			map->c_col = malloc(sizeof(char) * ft_strlen(map->colors[i]) - 1);
			while (map->colors[i][j])
				map->c_col[d++] = map->colors[i][j++];
			map->c_col[d] = '\0';	
		}
		i++;
	}
	printf("c = %s\n", map->c_col);
	printf("f = %s\n", map->f_col);
}

