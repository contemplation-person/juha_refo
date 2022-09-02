/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 18:11:47 by juha              #+#    #+#             */
/*   Updated: 2022/09/02 15:39:06 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../libft/libft.h"
#include "../libft/get_next_line.h"

static void	create_map(int fd, t_map *map)
{
	char	**temp;
	int		i;

	temp = NULL;
	map->map = NULL;
	map->y = 0;
	while (map->y == 0 || map->map[map->y - 1])
	{
		map->map = malloc(sizeof(char *) * (map->y + 1));
		if (!(map->map))
			exit(error_message("1-2 : malloc failed"));
		i = 0;
		while (i < map->y)
		{
			map->map[i] = temp[i];
			i++;
		}
		if (temp)
			free(temp);
		map->map[i] = get_next_line(fd);
		temp = map->map;
		map->y++;
	}
	if (!map->map[0])
		exit(error_message("1-2 : NULL"));
}

void	parsing(int argc, char **argv, t_map *map)
{
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (argc != 2 || fd < 0)
		exit(error_message("1-3 : parsing failed"));
	create_map(fd, map);
	map->x = ft_strlen(map->map[0]);
	if (map->x - 1 < 2)
		exit(error_message("1-4 : check your map"));
	check_map_element(map);
}
