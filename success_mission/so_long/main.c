/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 18:10:24 by juha              #+#    #+#             */
/*   Updated: 2022/09/02 18:51:28 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	copy_map(t_map map, t_map *cp_map)
{
	int	i;
	int	j;

	cp_map->map = malloc(sizeof(int *) * map.y);
	if (!(cp_map->map))
		exit(error_message("1.copy failed"));
	cp_map->x = map.x;
	cp_map->y = map.y;
	i = -1;
	while (++i < map.y)
	{
		j = -1;
		cp_map->map[i] = malloc(sizeof(int) * map.x);
		if (!(cp_map->map[i]))
			exit(error_message("2.copy failed"));
		while (++j < map.x)
		{
			cp_map->map[i][j] = map.map[i][j];
		}
	}
}

void	init_player_x_y(t_map m, t_element *player)
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
			{
				player->x = j;
				player->y = i;
			}
		}
	}
}

int	game_exit(int keycode, t_all *a)
{
	(void)(*a);
	(void)keycode;
	exit(0);
}

int	main(int argc, char **argv)
{
	t_all	*temp;
	t_all	a;

	temp = malloc(sizeof(t_all));
	a = *temp;
	parsing(argc, argv, &(a.m));
	a.v.mlx = mlx_init();
	a.v.win = mlx_new_window(a.v.mlx, a.m.x * 32, a.m.y * 32, "so_long");
	init_img(a.v, &(a.i));
	copy_map(a.m, &(a.cp_m));
	init_player_x_y(a.m, &(a.p));
	view_map(a.v, a.m, a.i);
	view_element(a.v, a.m, a.i);
	mlx_hook(a.v.win, X_EVENT_KEY_PRESS, 0, &key_press, &a);
	mlx_hook(a.v.win, BUTTON_X, 0, &game_exit, &a);
	mlx_hook(a.v.win, X_EVENT_KEY_RELEASE, 0, &check_done, &a);
	mlx_loop(a.v.mlx);
	return (0);
}
