/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_text2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isouaidi <isouaidi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 13:21:11 by isouaidi          #+#    #+#             */
/*   Updated: 2024/06/18 14:50:17 by isouaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

char	*textmap(char **tab, char a, char b)
{
	int		i;
	int		j;
	int		c;
	char	*str;

	i = 0;
	while (tab[i])
	{
		if (tab[i][0] == a && tab[i][1] == b)
		{
			j = 2;
			c = 0;
			while (tab[i][j] == ' ')
				j++;
			str = malloc(sizeof(char) * (ft_strlen(tab[i]) - j + 1));
			while (tab[i][j])
				str[c++] = tab[i][j++];
			return (str);
		}
		i++;
	}
	return (NULL);
}

void	rctext(t_map *map)
{
	map->_no = textmap(map->text, 'N', 'O');
	map->_ea = textmap(map->text, 'E', 'A');
	map->_so = textmap(map->text, 'S', 'O');
	map->_we = textmap(map->text, 'W', 'E');
}
