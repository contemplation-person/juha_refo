/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 12:12:59 by juha              #+#    #+#             */
/*   Updated: 2022/08/30 17:03:07 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define X_EVENT_KEY_PRESS			2
# define X_EVENT_KEY_RELEASE		3
# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2
# define TRUE			-1
# define FALSE			0
# include "mlx.h"
# include "./libft/get_next_line.h"
# include "./libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

enum
{
	PLAYER = 0,
	COLLECTION,
	EXIT,
	LOAD,
	WALL,
}e_map_element;

typedef struct s_var
{
	void	*mlx;
	void	*win;
}t_var;

typedef struct s_param
{
	int	x;
	int	y;
}t_param;

typedef struct s_img
{
	void	*img;
	int		x;
	int		y;
}t_img;

typedef struct s_map_element
{
	t_img	player;
	t_img	home;
	t_img	food;
	t_img	wall;
	t_img	load;
	t_img	villain;
}t_map_element;

typedef struct s_map
{
	int		x;
	int		y;
	int		pos_player[2];
	int		pos_home[2];
	int		pos_food[2];
	char	**map;
}t_map;

void	play_game(t_map *map, t_var vars, t_map_element *element);

void	init_game_img(t_map	map, t_var vars, t_map_element *element);
void	init_map(t_map	map, t_var vars, t_map_element *element);
void	view_player(t_var vars, t_map_element element);
void	review_img_element(t_map *map, t_var vars, t_param *param, \
t_map_element src);

int		error_message(char *message);
void	check_map_element(t_map *map);
void	parsing(int argc, char **argv, t_map *map);

#endif