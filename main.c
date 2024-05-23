/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isouaidi <isouaidi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 18:46:52 by isouaidi          #+#    #+#             */
/*   Updated: 2024/05/23 20:47:57 by isouaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	main(int ac, char **av)
{
	t_map	map;

	if (ac == 2)
	{
		apl_pars(&map, av);
		int i = 0;
		while (map.int_f[i])
		{
			printf("ok = %d\n", map.int_f[i++]);
		}
		free_all(&map);
		
	}
}
