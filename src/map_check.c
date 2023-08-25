/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmita <mmita@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:27:43 by mmita             #+#    #+#             */
/*   Updated: 2023/08/24 15:17:59 by mmita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	map_error(t_err *map_err)
{
	if (map_err->inv_borders)
	{
		perror("Error\nEl mapa debe estar rodeado de paredes\n");
		exit(EXIT_FAILURE);
	}
	if (map_err->inv_char)
	{
		perror("Error\nLetra(s) No Idenficada\n");
		exit(EXIT_FAILURE);
	}
	if (map_err->inv_n_collect)
	{
		perror("Error\nDeben ser mas de un Coleccionable\n");
		exit(EXIT_FAILURE);
	}
	if (map_err->inv_n_players || map_err->inv_n_exits)
	{
		perror("Error\nNo debe haber mas de un jugador o salida\n");
		exit(EXIT_FAILURE);
	}
	if (map_err->inv_rowlen)
	{
		perror("Error\nEl mapa debe ser rectangular\n");
		exit(EXIT_FAILURE);
	}
}

void	map_check(void)
{
	char	**map;
	t_err	map_err;

	map = NULL;
	map_error(&map_err);
}
