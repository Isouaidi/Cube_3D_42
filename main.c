/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isouaidi <isouaidi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 18:46:52 by isouaidi          #+#    #+#             */
/*   Updated: 2024/05/21 19:38:17 by isouaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	main(int ac, char **av)
{
	t_map	map;

	if (ac == 2)
	{
		check_name_cube(av[1]);
		size_fd(&map, av[1]);
		recup(&map, av[1]);
		check_texture(&map);
		check_colors(&map);
		tab_col(&map, 0, 0);
		recup_map(&map);
	}
}
