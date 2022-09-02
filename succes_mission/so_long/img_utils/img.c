/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 20:41:49 by juha              #+#    #+#             */
/*   Updated: 2022/09/02 15:39:24 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_img(t_var var, t_img *img)
{
	int	x;
	int	y;

	img->c_1 = mlx_xpm_file_to_image(var.mlx, "./img/coin1.xpm", &x, &y);
	img->c_2 = mlx_xpm_file_to_image(var.mlx, "./img/coin2.xpm", &x, &y);
	img->c_3 = mlx_xpm_file_to_image(var.mlx, "./img/coin3.xpm", &x, &y);
	img->c_4 = mlx_xpm_file_to_image(var.mlx, "./img/coin4.xpm", &x, &y);
	img->p = mlx_xpm_file_to_image(var.mlx, "./img/mario.xpm", &x, &y);
	img->v = mlx_xpm_file_to_image(var.mlx, "./img/gomba.xpm", &x, &y);
	img->e = mlx_xpm_file_to_image(var.mlx, "./img/pip.xpm", &x, &y);
	img->load = mlx_xpm_file_to_image(var.mlx, "./img/load.xpm", &x, &y);
	img->wall = mlx_xpm_file_to_image(var.mlx, "./img/wall.xpm", &x, &y);
}

void	view_map(t_var v, t_map m, t_img img)
{
	int	i;
	int	j;

	i = -1;
	while (++i < m.y)
	{
		j = -1;
		while (++j < m.x)
		{
			if (m.map[i][j] == '1')
				mlx_put_image_to_window(v.mlx, v.win, img.wall, j * 32, i * 32);
			else if (m.map[i][j] == 'E')
				mlx_put_image_to_window(v.mlx, v.win, img.e, j * 32, i * 32);
			else
				mlx_put_image_to_window(v.mlx, v.win, img.load, j * 32, i * 32);
		}
	}
}

void	view_element(t_var v, t_map m, t_img img)
{
	int	i;
	int	j;

	i = -1;
	while (++i < m.y)
	{
		j = -1;
		while (++j < m.x)
		{
			if (m.map[i][j] == 'P')
				mlx_put_image_to_window(v.mlx, v.win, img.p, j * 32, i * 32);
			else if (m.map[i][j] == 'C')
				mlx_put_image_to_window(v.mlx, v.win, img.c_1, j * 32, i * 32);
			else if (m.map[i][j] == 'V')
				mlx_put_image_to_window(v.mlx, v.win, img.v, j * 32, i * 32);
		}
	}
}
