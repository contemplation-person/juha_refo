/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 18:11:47 by juha              #+#    #+#             */
/*   Updated: 2022/08/24 19:02:34 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

int	main(int argc, char **argv)
{
	t_img	i;
	t_var	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 700, 700, "so_long");
	i.img = mlx_xpm_file_to_image(vars.mlx, "./img/coin1.xpm", &i.x, &i.y);
	i.img = mlx_xpm_file_to_image(vars.mlx, "./img/coin2.xpm", &i.x, &i.y);
	i.img = mlx_xpm_file_to_image(vars.mlx, "./img/coin3.xpm", &i.x, &i.y);
	i.img = mlx_xpm_file_to_image(vars.mlx, "./img/coin4.xpm", &i.x, &i.y);
	i.img = mlx_xpm_file_to_image(vars.mlx, "./img/gomba.xpm", &i.x, &i.y);
	i.img = mlx_xpm_file_to_image(vars.mlx, "./img/load.xpm", &i.x, &i.y);
	i.img = mlx_xpm_file_to_image(vars.mlx, "./img/mario.xpm", &i.x, &i.y);
	i.img = mlx_xpm_file_to_image(vars.mlx, "./img/pip.xpm", &i.x, &i.y);
	i.img = mlx_xpm_file_to_image(vars.mlx, "./img/wall.xpm", &i.x, &i.y);
	mlx_loop(vars.mlx);
	return (0);
}