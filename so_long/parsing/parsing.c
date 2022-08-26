/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 18:11:47 by juha              #+#    #+#             */
/*   Updated: 2022/08/27 04:33:34 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	create_map(int fd, t_map map)
{
	char	**temp;
	int		i;

	map.map = NULL;
	map.y = -1;
	while (++(map.y) == 0 || !(map.map[map.y]))
	{
		if (map.map == NULL)
		{
			map.map = malloc(sizeof(char *));
			if (!(map.map))
				exit(error_message("1-2 : NULL"));
			map.map[0] = NULL;
		}
		else
		{
			temp = malloc(sizeof(char *) * (map.y + 1));
			if (!temp)
				exit(error_message("1-3 : NULL"));
			i = -1;
			while (++i < map.y)
				temp[i] = map.map[i];
			free(map.map);
			map.map = temp;
		}
		map.map[map.y] = get_next_line(fd);
	}
	if (!map.map[0])
		exit(error_message("1-4 : NULL"));
}

char	**parsing(int argc, char **argv, t_map map)
{
	int		fd;

	fd = open(argv[0], O_RDONLY);
	if (argc != 2 && fd < 0)
		exit(error_message("1-1 : parsing failed"));
	create_map(fd, map);
	map.x = ft_strlen(map.map[0]);
	check_map_size(map);
	while ()
	
}
