/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*	 	  	                                              :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 18:11:47 by juha              #+#    #+#             */
/*   Updated: 2022/08/29 14:08:22 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	view_player(t_var vars, t_map_element element)
{
	mlx_put_image_to_window(vars.mlx, vars.win, element.player.img, \
	element.player.x, element.player.y);
}

void	init_map(t_map	map, t_var vars, t_map_element *element)
{
	int	x;
	int	y;

	y = -1;
	while (++y < map.y - 1)
	{
		x = -1;
		while (++x < map.x)
		{
			if (map.map[y][x] == '1')
			{
				mlx_put_image_to_window(vars.mlx, vars.win, element->wall.img, \
					x * 32, y * 32);
			}
			else
				mlx_put_image_to_window(vars.mlx, vars.win, element->load.img, \
					x * 32, y * 32);
			if (map.map[y][x] == 'E')
				mlx_put_image_to_window(vars.mlx, vars.win, element->home.img, \
					x * 32, y * 32);
			if (map.map[y][x] == 'C')
				mlx_put_image_to_window(vars.mlx, vars.win, element->food.img, \
					x * 32, y * 32);
		}
	}
}

void	init_game_img(t_map map, t_var vars, t_map_element *element)
{
	element->food.img = mlx_xpm_file_to_image(vars.mlx, "./img/coin1.xpm", \
	&(element->food.x), &(element->food.y));
	element->home.img = mlx_xpm_file_to_image(vars.mlx, "./img/pip.xpm", \
	&(element->home.x), &(element->home.y));
	element->player.img = mlx_xpm_file_to_image(vars.mlx, "./img/mario.xpm", \
	&(element->player.x), &(element->player.y));
	element->villain.img = mlx_xpm_file_to_image(vars.mlx, "./img/gomba.xpm", \
	&(element->villain.x), &(element->villain.y));
	element->load.img = mlx_xpm_file_to_image(vars.mlx, "./img/load.xpm", \
	&element->load.x, &element->load.y);
	element->load.x = 0;
	element->load.y = 0;
	element->wall.img = mlx_xpm_file_to_image(vars.mlx, "./img/wall.xpm", \
	&element->wall.x, &element->wall.y);
	element->wall.x = 0;
	element->wall.y = 0;
	element->home.x = map.pos_home[0];
	element->home.y = map.pos_home[1];
	element->player.x = map.pos_player[0] * 32;
	element->player.y = map.pos_player[1] * 32;
}

// void	review_img_player(t_map *map, t_var vars, \
// t_param *param, t_map_element src)
// {
// 	mlx_put_image_to_window(vars.mlx, vars.win, src.load.img, \
// 	param->x, param->y);
// 	mlx_put_image_to_window(vars.mlx, vars.win, src.player.img, \
// 	param->x, param->y);
// }

// void	review_img_villain(t_map *map, t_var vars, \
// t_param *param, t_map_element src)
// {
// 	mlx_put_image_to_window(vars.mlx, vars.win, src.load.img, \
// 	param->x, param->y);
// 	mlx_put_image_to_window(vars.mlx, vars.win, src.villain.img, \
// 	param->x, param->y);
// }
