/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 12:12:57 by juha              #+#    #+#             */
/*   Updated: 2022/08/26 21:30:21 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	error_message(char *message)
{
	int	i;

	i = 0;
	write(2, "error\n", 6);
	while (message[i])
		i++;
	write(2, message, i);
	write(2, "\n", 1);
	return (1);
}

int	so_long()
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
