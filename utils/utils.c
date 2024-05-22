/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isouaidi <isouaidi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:01:50 by isouaidi          #+#    #+#             */
/*   Updated: 2024/05/22 18:42:27 by isouaidi         ###   ########.fr       */
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
		}
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}