/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 18:11:47 by juha              #+#    #+#             */
/*   Updated: 2022/08/27 04:33:27 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	check_map_size(t_map map, char *p_map, int y)
{
	static int	check_y;
	int			i;

	check_y++;
	i = 0;
	if (!(map.map))
		exit(error_message("1-5 : empty"));
	while (*(map.map + i++))
		;
	if ((map.x + 1) * (map.y + 1) != i)
		exit(error_message("check map size"));
}

static void	recoding_element_x(t_map map, int pos, char c, int coordinate)
{
	static int	check[3];

	if (c == 'C')
	{
		check[COLLECTION]++;
		map.pos_food[coordinate] = pos;
	}
	else if (c == 'E')
	{
		map.pos_home[coordinate] = pos;
		check[EXIT]++;
	}
	else if (c == 'P')
	{
		map.pos_player[coordinate] = pos;
		check[PLAYER]++;
	}
	if (coordinate == 3)
	{
		if (check[0] != 1 && check[1] != 1 && check[2] != 1)
			exit(error_message("check your map element"));
	}
}

static int	exist_element(t_map map, char *p_map, int y)
{
	int			i;

	i = -1;
	while (p_map[++i])
	{
		if (p_map[i] != 'C' || p_map[i] != 0 \
		|| p_map[i] != 1 || p_map[i] != 'E' || p_map[i] != 'P')
			exit("1-6 : plz check map element");
		else if (p_map[i] == 'C')
			map.pos_food[1] = y;
		else if (p_map[i] == 'P')
			map.pos_player[1] = y;
		else if (p_map[i] == 'E')
			map.pos_home[1] = y;
		recoding_element_x(map, i, p_map[i], 2);
	}
	recoding_element_x(map, -1, -1, 3);
}

void	check_wall(t_map map, char *p_map, int y)
{
	int		i;

	if (y != 0 && y != map.y)
	{
		if (p_map[0] != 1 || p_map[map.x] != 1)
			exit(error_message("no wall"));
	}
	else
	{
		i = 0;
		while (p_map[i])
		{
			if (p_map[i] != 1)
				exit(error_message("no wall"));
		}
	}
}

void	check_map_element(t_map map)
{
	int		i;

	i = 0;
	while (i < map.y)
	{
		check_wall(map, map.map[i], map.y);
		exist_element(map, map.map[i], i);
		check_map_size(map, map.map[i], i);
		i++;
	}
}
