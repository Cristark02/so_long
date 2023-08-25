/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmita <mmita@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:21:54 by mmita             #+#    #+#             */
/*   Updated: 2023/08/24 14:18:13 by mmita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_layout(char *line, t_err *map_err, t_lay *lay, int is_last)
{
	if (!lay->col)
		lay->col = ft_strlen(line) - 1;
	if (lay->col && ((lay->col != (int)ft_strlen(line) - 1 && \
			ft_strchr(line, '\n')) || (lay->col != (int)ft_strlen(line) && \
			!ft_strchr(line, '\n'))))
		map_err->inv_rowlen = 1;
	if (line[0] != '1' || line[lay->col - 1] != '1' || \
			(ft_countchar(line, '1') != lay->col && is_last))
		map_err->inv_borders = 1;
	lay->exit += ft_countchar(line, 'E');
	lay->pl += ft_countchar(line, 'P');
	lay->collect += ft_countchar(line, 'C');
	map_err->inv_n_exits = lay->exit < 1;
	map_err->inv_n_players = lay->pl < 1;
	map_err->inv_n_collect = lay->collect < 1;
	while (line && *line)
	{
		if (!ft_strchr("01CEP\n", *line))
			map_err->inv_char = 1;
		line++;
	}
}

void	read_layout(int file, t_err *map_err, t_lay *layout, char **map_str)
{
	char		*line;
	char		*last_line;

	line = NULL;
	last_line = NULL;
	while (1)
	{
		line = get_next_line(file);
		if (!line)
		{
			if (!layout->col)
			{
				perror("Error\nEl mapa esta vacio\n");
				exit(EXIT_FAILURE);
			}
			else
				check_layout(last_line, map_err, layout, 1);
			free(last_line);
			break ;
		}
		free(last_line);
		check_layout(line, map_err, layout, !layout->row);
		last_line = ft_substr(line, 0, ft_strlen(line));
		*map_str = ft_strenlarge(*map_str, line);
		layout->row++;
	}
}

void	read_map(int file)
{
	t_lay	layout;
	t_err	map_err;
	char	*map_str;
	char	**map;

	map_str = NULL;
	map = NULL;
	read_layout(file, &map_err, &layout, &map_str);
	map = ft_split(map_str, '\n');
	free(map_str);
	if (!map)
	{
		perror("Error\nMemoria Perdida\n");
		exit(EXIT_FAILURE);
	}
}
