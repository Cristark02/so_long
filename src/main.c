/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmita <mmita@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 13:15:56 by mmita             #+#    #+#             */
/*   Updated: 2023/08/25 18:23:50 by mmita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <stdio.h>

void imprimirArgumentos(int argc, char **argv) {
    for (int i = 0; i < argc; i++) {
        printf("Argumento %d: %s\n", i, argv[i]);
    }
}

int	main(int argc, char **argv)
{
	t_game	data;
	int		fd;

	if (argc != 2)
	{
		perror("Error\nCantidad de argumentos incorrectos\n");
		exit(EXIT_FAILURE);
	}
	imprimirArgumentos(argc, argv);
	init(&data);
	file_check(&argv[1]);
	fd = open(argv[1], O_RDONLY);
	read_map(fd);
	map_check();
	close(fd);
	// window(&data);
	// gameplay(&data);
	// finish(&data);
	return (0);
}
