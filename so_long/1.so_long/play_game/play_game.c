/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 19:53:45 by juha              #+#    #+#             */
/*   Updated: 2022/08/30 18:57:10 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	key(int keycode, t_param *param)
{
	if (keycode == KEY_ESC)
		exit(0);
	else if (keycode == KEY_W)
		param->y++ ;
	else if (keycode == KEY_S)
		param->y-- ;
	else if (keycode == KEY_A)
		param->x-- ;
	else if (keycode == KEY_D)
		param->x++ ;
	return (0);
}

void	check_coin(t_map *map, unsigned int *coin)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < map->y)
	{
		while (j < map->x)
		{
			if (map->map[i][j] == 'C')
				(*coin)++;
			j++;
		}
		i++;
	}
}

int	move_play(t_map *map, t_var vars, t_param *player)
{
	t_param	tmp;

	tmp.x = player->x;
	tmp.y = player->y;
	mlx_hook(vars.win, X_EVENT_KEY_RELEASE, 0, &key, &player);
	if (map->map[player->y][player->x] == '1')
	{
		player->y = tmp.y;
		player->x = tmp.x;
		return (0);
	}
	if (map->map[player->y][player->x] == 'C')
		map->map[player->y][player->x] = 0;
	if (map->map[player->y][player->x] == 'E')
		return (2);
	return (1);
}

// void	play_game(t_map *map, t_var vars, t_map_element *element)
// {
// 	static unsigned int	coin;
// 	static t_param		param;
// 	static size_t		move;
// 	int					check;

// 	param.x = element->player.x / 32;
// 	param.y = element->player.y / 32;
// 	mlx_put_image_to_window(vars.mlx, vars.win, \
// 	element->player.img, element->player.x, element->player.y);
// 	check_coin(map, &coin);
// 	while (1)
// 	{
// 		check = move_play(map, vars, &param);
// 		if (check != 0)
// 		{
// 			review_img_player(map, vars, &param, *element);
// 			move++;
// 		}
// 		if (coin == 0)
// 			exit(0);
// 	}	
// }
