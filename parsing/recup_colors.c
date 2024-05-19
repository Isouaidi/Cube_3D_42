/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isouaidi <isouaidi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:59:07 by isouaidi          #+#    #+#             */
/*   Updated: 2024/05/20 01:19:46 by isouaidi         ###   ########.fr       */
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

int		count_tab(char **tab)
{
	int i; 
	
	i = 0;
	while (tab[i] != NULL)
		i++;
	printf("%d\n", i);
	return(i);
}
void	check_int_col(t_map *map)
{
	int i; 
	
	i = 0;
	printf("t = %s", map->c_col);
	while (map->c_col[i])
	{
		// if((map->c_col[i] >= '0' && map->c_col[i] <= '9' )&& map->c_col[i] == ',') 
		// 	i++;
		// else
		//  	ft_exit(NBR_COLORS);
		printf("ok = %c\n", map->c_col[i]);
		i++;
	}
	
}
void	convert(char **str, int *col)
{
	int i;
	int b;

	b = 0;
	i = count_tab(str);
	// if (i != 3)
		// ft_exit(NBR_COLORS); 
	i = 0;
	while (str[i])
	{ 
		col[b] = ft_atoi(str[i]);
		printf("col int = %d\n",col[b]);
		printf("col char = %s\n",str[i]);
		b++;
		i++;
	}
}
void	char_int(t_map *map)
{
	char **f;
	char **c;

	check_int_col(map);
	f = ft_split(map->f_col, ',');
	c = ft_split(map->c_col, ',');
	if (count_tab(f) != 3 || count_tab(c) != 3 )
		ft_exit(NBR_COLORS);
	map->int_f = malloc(sizeof(int *) * 3);	
	map->int_c = malloc(sizeof(int *) * 3);
	convert(f, map->int_f);
	convert(c, map->int_c);
	int i = 0;
	while (i < 3)
	{
		if ((map->int_c[i] < 0 || map->int_c[i] > 255) 
			|| (map->int_f[i] < 0 || map->int_f[i] > 255))
			ft_exit(COLORS_ERREUR);
		i++;
	}
}
void	tab_col(t_map *map, int i, int j, int d)
{
	while (map->colors[i])
	{
		d = 0;
		j = 2;
		if (map->colors[i][j - 2] == 'F')
		{
			map->f_col = malloc(sizeof(char) * ft_strlen(map->colors[i]) - 2);
			while (map->colors[i][j])
				map->f_col[d++] = map->colors[i][j++];
			map->f_col[d] = '\0';	
		}
		else if (map->colors[i][j - 2] == 'C')
		{
			map->c_col = malloc(sizeof(char) * ft_strlen(map->colors[i]) - 2);
			while (map->colors[i][j])
				map->c_col[d++] = map->colors[i][j++];
			map->c_col[d] = '\0';	
		}
		i++;
	}
	char_int(map);
	// printf("c = %s\n", map->c_col);
	// printf("f = %s\n", map->f_col);
}
