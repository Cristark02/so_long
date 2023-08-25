/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmita <mmita@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:39:57 by mmita             #+#    #+#             */
/*   Updated: 2023/08/25 18:31:12 by mmita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init(t_game *data)
{
	data->layout.row = 0;
	data->layout.col = 0;
	data->layout.exit = 0;
	data->layout.pl = 0;
	data->layout.collect = 0;
	data->err_lay.inv_borders = 0;
	data->err_lay.inv_char = 0;
	data->err_lay.inv_n_collect = 0;
	data->err_lay.inv_n_exits = 0;
	data->err_lay.inv_n_players = 0;
	data->err_lay.inv_rowlen = 0;
}
