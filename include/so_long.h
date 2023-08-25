/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmita <mmita@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 16:14:21 by mmita             #+#    #+#             */
/*   Updated: 2023/08/25 18:27:27 by mmita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <memory.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "../libs/MLX42/include/MLX42/MLX42.h"
# include "../libs/Libft+/libft.h"
# include "../libs/get_next_line/get_next_line.h"
# define WIDTH 1000
# define HEIGHT 1000
# define SQ_WIDTH 96
# define SQ_HEIGHT 80
# define BPP sizeof(int32_t)

//disposicion del mapa
typedef struct s_lay
{
	int	row;
	int	col;
	int	exit;
	int	pl;
	int	collect;
}				t_lay;

//errores de disposicion del mapa
typedef struct s_err
{
	int	inv_rowlen;
	int	inv_char;
	int	inv_n_players;
	int	inv_n_collect;
	int	inv_n_exits;
	int	inv_borders;
}				t_err;

typedef struct s_game
{
	t_lay	layout;
	t_err	err_lay;
}	t_game;

void	init(t_game *data);
void	file_check(char **argv);
void	read_map(int file);
void	map_check(void);

#endif