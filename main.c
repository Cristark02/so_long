/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmita <mmita@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 16:16:25 by mmita             #+#    #+#             */
/*   Updated: 2023/08/18 17:36:10 by mmita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

mlx_image_t		*g_img;

void	hook(void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP) && g_img->instances[0].y > 0)
		g_img->instances[0].y -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN)
		&& g_img->instances[0].y < HEIGHT - SQ_HEIGHT)
		g_img->instances[0].y += 5;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT) && g_img->instances[0].x > 0)
		g_img->instances[0].x -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT)
		&& g_img->instances[0].x < WIDTH - SQ_WIDTH)
		g_img->instances[0].x += 5;
}

int32_t	main(void)
{
	mlx_t			*mlx;
	mlx_texture_t	*texture;

	mlx = mlx_init(WIDTH, HEIGHT, "test del cuadrao", false);
	if (!mlx)
		exit(EXIT_FAILURE);
	texture = mlx_load_png("P-O-T-A-T-O.png");
	g_img = mlx_texture_to_image(mlx, texture);
	mlx_image_to_window(mlx, g_img,
		(WIDTH / 2) - (SQ_WIDTH / 2), (HEIGHT / 2) - (SQ_HEIGHT / 2));
	mlx_loop_hook(mlx, &hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}