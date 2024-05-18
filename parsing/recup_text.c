/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_text.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isouaidi <isouaidi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:49:38 by isouaidi          #+#    #+#             */
/*   Updated: 2024/05/16 16:58:27 by isouaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

char	*without_space(char *s)
{
	int	i;

	i = 0;
	while (s[i] == ' ' && s[i] == '\t')
		i++;
	return (s + i);
}

bool	is_texture(char *s)
{
	if (s[0] == 'N' && s[1] == 'O' && (s[2] == ' ' || s[2] == '\t'))
		return (true);
	else if (s[0] == 'W' && s[1] == 'E' && (s[2] == ' ' || s[2] == '\t'))
		return (true);
	else if (s[0] == 'E' && s[1] == 'A' && (s[2] == ' ' || s[2] == '\t'))
		return (true);
	else if (s[0] == 'S' && s[1] == 'O' && (s[2] == ' ' || s[2] == '\t'))
		return (true);
	else
		return (false);
}

void	check_texture(t_map *map)
{
	map->text = malloc(sizeof(char *) * 5);
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (map->file[i])
	{
		map->file[i] = without_space(map->file[i]);
		if (is_texture(map->file[i]) == true)
		{
			if (count == 4)
				ft_exit(TOO_MUCH_TEXTURES);
			map->text[j] = ft_strdup(map->file[i]);
			j++;
			count++;
		}
		i++;
	}
	map->text[j] = NULL;
	print_char_tab(map->text);	
}
