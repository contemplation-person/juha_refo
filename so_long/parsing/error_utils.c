/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 18:11:47 by juha              #+#    #+#             */
/*   Updated: 2022/08/28 20:36:07 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../libft/libft.h"
#include "../libft/get_next_line.h"

static void	check_map_size(t_map *map, char *p_map, int flag)
{		
	if (!(map->map))
		exit(error_message("2-1 : empty"));
	if (map->x != (int)ft_strlen(p_map) && flag != 1)
		exit(error_message("2-2 : check your map"));
	else if (flag == 1 && map->x - 1 != (int)ft_strlen(p_map))
		exit(error_message("2-3 : check your map"));
}

static void	recoding_element_x(t_map *map, int pos, char c, int coordinate)
{
	static int	check[3];

	if (c == 'C')
	{
		check[COLLECTION]++;
		map->pos_food[coordinate] = pos;
	}
	else if (c == 'E')
	{
		map->pos_home[coordinate] = pos;
		check[EXIT]++;
	}
	else if (c == 'P')
	{
		map->pos_player[coordinate] = pos;
		check[PLAYER]++;
	}
	if (coordinate == 3)
	{
		if (check[0] != 1 || check[1] != 1 || check[2] != 1)
			exit(error_message("2-3 : check your map element"));
	}
}

static void	exist_element(t_map *map, char *p_map, int y)
{
	int			i;

	i = 0;
	while (p_map[i])
	{
		if (p_map[i] == '\n')
		{
			i++;
			continue ;
		}
		if (p_map[i] != 'P' && p_map[i] != 'C' && \
		p_map[i] != 'E' && p_map[i] != '1' && p_map[i] != '0')
			exit(error_message("2-4 : plz check map element"));
		else if (p_map[i] == 'C')
			map->pos_food[1] = y;
		else if (p_map[i] == 'P')
			map->pos_player[1] = y;
		else if (p_map[i] == 'E')
			map->pos_home[1] = y;
		recoding_element_x(map, i, p_map[i], 0);
		i++;
	}
}

static void	check_wall(t_map *map, char *p_map, int y)
{
	int		i;

	if (y == map->y)
		return ;
	if (y != 0 && y != (map->y - 1))
	{
		if (p_map[0] != '1' || p_map[map->x - 2] != '1')
			exit(error_message("2-6:no wall"));
	}
	else
	{
		i = 0;
		while (p_map[i])
		{
			if (p_map[i] != 1)
				exit(error_message("2-7:no wall"));
		}
	}
}

void	check_map_element(t_map *map)
{
	int		i;

	i = 0;
	while (i < map->y - 1)
	{
		check_wall(map, map->map[i], map->y);
		if (i == map->y - 2)
			check_map_size(map, map->map[i], 1);
		else
			check_map_size(map, map->map[i], 0);
		exist_element(map, map->map[i], i);
		i++;
	}
	recoding_element_x(map, -1, 0, 3);
}
