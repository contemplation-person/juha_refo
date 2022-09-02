/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 21:48:35 by juha              #+#    #+#             */
/*   Updated: 2022/09/02 18:49:35 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	print_cnt(t_all *a, unsigned int cnt)
{
	char	*str;

	str = ft_itoa(cnt);
	mlx_string_put(a->v.mlx, a->v.win, a->m.x / 2 * 32, a->m.y / 2 * 32, \
	0x444444, str);
	free (str);
}
