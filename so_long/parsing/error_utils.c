/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 18:11:47 by juha              #+#    #+#             */
/*   Updated: 2022/08/31 17:11:53 by juha             ###   ########seoul.kr  */
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

static void	check_p_e_c(int check[], char c)
{
	if (c == 'P')
		check[PLAYER]++;
	if (c == 'C')
		check[COLLECTION]++;
	if (c == 'E')
		check[EXIT]++;
}

static void	exist_element(t_map *map)
{
	int			x;
	int			y;
	static int	check[3];

	y = -1;
	while (++y < map->y - 1)
	{
		x = -1;
		while (++x < map->x - 1)
		{
			if (map->map[y][x] != 'P' && map->map[y][x] != 'C' && \
			map->map[y][x] != 'E' && map->map[y][x] != '1' \
			&& map->map[y][x] != '0')
				exit(error_message("2-4 : plz check map element"));
			check_p_e_c(check, map->map[y][x]);
		}
	}
	map->x--;
	map->y--;
	if (check[PLAYER] != 1 || check[COLLECTION] < 1 || check[EXIT] != 1)
		exit(error_message("2-5 : check your element"));
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
		i++;
	}
	exist_element(map);
}
