/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isouaidi <isouaidi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:31:10 by isouaidi          #+#    #+#             */
/*   Updated: 2024/05/16 17:01:16 by isouaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>
# include <stdbool.h>

# include "../libft/inc/libft.h"
# include "../libft/inc/ft_printf.h"
# include "../libft/inc/get_next_line_bonus.h"

# define TOO_MUCH_TEXTURES "Error \nThere is too much textures" 

typedef struct s_map
{
	char	**file;
	int		size;
	char	**text;
	char	**colors;
	int		no;
	int		so;
	int		w;
	int		e;
	int		f;
	int		c;
}	t_map;

int		main(int ac, char **av);

//Pars :
void	size_fd(t_map *map, char *av);
void	recup(t_map *map, char *av);
void	ft_strcopy(char *dst, const char *src);
void	check_name_cube(char *av);
int		tablen(char **tab);
void	inti_var(t_map *map);
void	print_char_tab(char **tab);
void	check_texture(t_map *map);
void	ft_exit(char *str);

#endif