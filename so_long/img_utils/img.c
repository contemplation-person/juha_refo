/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 18:11:47 by juha              #+#    #+#             */
/*   Updated: 2022/08/28 21:10:31 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	view_img(t_map	map, t_var vars, t_img	img)
{
	(void)map;
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	// img.img = mlx_xpm_file_to_image(vars.mlx, "./img/coin2.xpm", &img.x, &img.y);
	// img.img = mlx_xpm_file_to_image(vars.mlx, "./img/coin3.xpm", &img.x, &img.y);
	// img.img = mlx_xpm_file_to_image(vars.mlx, "./img/coin4.xpm", &img.x, &img.y);
	// img.img = mlx_xpm_file_to_image(vars.mlx, "./img/gomba.xpm", &img.x, &img.y);
	// img.img = mlx_xpm_file_to_image(vars.mlx, "./img/load.xpm", &img.x, &img.y);
	// img.img = mlx_xpm_file_to_image(vars.mlx, "./img/mario.xpm", &img.x, &img.y);
	// img.img = mlx_xpm_file_to_image(vars.mlx, "./img/pip.xpm", &img.x, &img.y);
	// img.img = mlx_xpm_file_to_image(vars.mlx, "./img/wall.xpm", &img.x, &img.y);
	return (0);
}

t_img	save_img(t_map	map, t_var vars, int x, int y)
{
	t_img	img;

	img.x = x;
	img.y = y;
	img.x *= 32;
	img.y *= 32;

	(void )map;
	img.img = mlx_xpm_file_to_image(vars.mlx, "./img/coin1.xpm", &(img.x), &(img.y));
	// img.img = mlx_xpm_file_to_image(vars.mlx, "./img/coin2.xpm", &img.x, &img.y);
	// img.img = mlx_xpm_file_to_image(vars.mlx, "./img/coin3.xpm", &img.x, &img.y);
	// img.img = mlx_xpm_file_to_image(vars.mlx, "./img/coin4.xpm", &img.x, &img.y);
	// img.img = mlx_xpm_file_to_image(vars.mlx, "./img/gomba.xpm", &img.x, &img.y);
	// img.img = mlx_xpm_file_to_image(vars.mlx, "./img/load.xpm", &img.x, &img.y);
	// img.img = mlx_xpm_file_to_image(vars.mlx, "./img/mario.xpm", &img.x, &img.y);
	// img.img = mlx_xpm_file_to_image(vars.mlx, "./img/pip.xpm", &img.x, &img.y);
	// img.img = mlx_xpm_file_to_image(vars.mlx, "./img/wall.xpm", &img.x, &img.y);
	return (img);
}