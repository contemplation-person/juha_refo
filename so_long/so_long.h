/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 12:12:59 by juha              #+#    #+#             */
/*   Updated: 2022/09/01 20:27:50 by juha             ###   ########seoul.kr  */
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
# define BUTTON_X		17
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

typedef struct s_element
{
	int	x;
	int	y;
}t_element;

typedef struct s_img
{
	void	*wall;
	void	*load;
	void	*c_1;
	void	*c_2;
	void	*c_3;
	void	*c_4;
	void	*e;
	void	*v;
	void	*p;
}t_img;

typedef struct s_map
{
	int		x;
	int		y;
	char	**map;
}t_map;

typedef struct s_all
{
	t_var		v;
	t_img		i;
	t_map		m;
	t_map		cp_m;
	t_element	p;
}t_all;

int		check_done(int keycode, t_all *a);
int		is_in_the_coin(t_map m);
void	init_player_x_y(t_map m, t_element *player);
int		key_press(int keycode, t_all *a);

void	view_map(t_var v, t_map m, t_img img);
void	view_element(t_var v, t_map m, t_img img);
void	init_img(t_var var, t_img *img);

int		error_message(char *message);
void	check_map_element(t_map *map);
void	parsing(int argc, char **argv, t_map *map);

#endif