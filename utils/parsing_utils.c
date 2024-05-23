/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isouaidi <isouaidi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:01:50 by isouaidi          #+#    #+#             */
/*   Updated: 2024/05/23 20:10:44 by isouaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	count_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
		i++;
	return (i);
}
char	*modif_ft_strdup(const char *src)
{
	char	*dest;
	int		i;

	i = 0;
	dest = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!dest)
		return (0);
	while (src[i])
	{
		if (src[i] == '\n')
		{
			dest[i] = '\0';
			i++;
			return(dest);
		}
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
void free_tab(char **tab)
{
	int i;

	i = -1;
	while(tab[++i])
		free(tab[i]);
	free(tab);
}
char	*free_strjoins1(char *s1, char *s2)
{
	int		i;
	int		c;
	char	*result;

	i = 0;
	c = 0;
	if (!s1 || !s2)
		return (0);
	result = malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!result)
		return (0);
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	while (s2[c])
	{
		result[i] = s2[c];
		i++;
		c++;
	}
	result[i] = '\0';
	free(s1);
	return (result);
}
char	*free_strjoins2(char *s1, char *s2)
{
	int		i;
	int		c;
	char	*result;

	i = 0;
	c = 0;
	if (!s1 || !s2)
		return (0);
	result = malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!result)
		return (0);
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	while (s2[c])
	{
		result[i] = s2[c];
		i++;
		c++;
	}
	result[i] = '\0';
	if (s2 != NULL)
		free(s2);
	return (result);
}
void free_all(t_map *map)
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

