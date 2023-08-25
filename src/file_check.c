/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmita <mmita@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:21:48 by mmita             #+#    #+#             */
/*   Updated: 2023/08/25 18:44:11 by mmita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h" 

void	file_check(char **argv)
{
	// if ( < 0)
	// {
	// 	perror("Error\nNo se encuentra el mapa\n");
	// 	exit(EXIT_FAILURE);
	// }
		printf("holas\n");
	if (ft_strrncmp(argv[1], ".ber", 4))
	{
		perror("Error\nExtension del archivo incorrecta\n");
		exit(EXIT_FAILURE);
	}
	else if (ft_strlen(argv[1]) < 5)
	{
		perror("Error\nFalta el nombre del archivo\n");
		exit(EXIT_FAILURE);
	}
}
