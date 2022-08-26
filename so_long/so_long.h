/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 12:12:59 by juha              #+#    #+#             */
/*   Updated: 2022/08/26 20:13:10 by juha             ###   ########seoul.kr  */
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
# include "get_next_line.h"
# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

enum
{
	PLAYER = 0,
	COLLECTION,
	EXIT,	
}e_map_element;

int		error_message(char *message);
char	**parsing(int argc, char **argv, t_map map);

typedef struct s_var
{
	void	*mlx;
	void	*win;
}t_var;

typedef struct s_img
{
	void	*img;
	int		x;
	int		y;
}t_img;

typedef struct s_map
{
	int		x;
	int		y;
	int		pos_player[2];
	int		pos_home[2];
	int		pos_food[2];
	char	**map;
}t_map;

#endif