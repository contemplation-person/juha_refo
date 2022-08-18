/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 12:12:57 by juha              #+#    #+#             */
/*   Updated: 2022/08/18 15:51:05 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

/*
	이미지 주소는 있지만 아직 pixel이 없다.
	우리가 이를 위한 작업을 시작하기 전에 bytes가 정렬되어 있지 않음을 이해해야 한다.
	즉 line_length가 실제 창(window) 너비와 다를 수 있다는 것이다.

	그래서 우리는 언제나 mlx_get_data_addr 을 통해 set된 line length를 가지고 메모리 주소 출발점(offset) 을 계산해야 한다.
	우리는 다음 공식을 통해 그것을 쉽게 구해낼 수 있다.
	int offset = (y * line_length + x * (bits_per_pixel / 8));
*/

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	// 괄호 == offset
	*(unsigned int *)dst = color;
}

int	main(void)
{
	t_data	img;
	t_var	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 500, 500, "so_long");
	img.img = mlx_new_image(vars.mlx, 500, 500);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
									&img.line_length, &img.endian);
	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_loop(vars.mlx);
}
