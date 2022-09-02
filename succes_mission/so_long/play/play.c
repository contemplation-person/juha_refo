/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 21:48:35 by juha              #+#    #+#             */
/*   Updated: 2022/09/02 18:51:28 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	is_in_the_coin(t_map m)
{
	int	x;
	int	y;

	y = -1;
	while (++y < m.y)
	{
		x = -1;
		while (++x < m.x)
		{
			if (m.map[y][x] == 'C')
				return (1);
		}
	}
	return (0);
}

int	check_done(int keycode, t_all *a)
{
	(void)keycode;
	if (!is_in_the_coin(a->m) && a->cp_m.map[a->p.y][a->p.x] == 'E')
		exit(0);
	return (0);
}

void	save_p_pos(t_all *a, int *x, int *y, int mark)
{
	if (mark)
	{
		*x = a->p.x;
		*y = a->p.y;
	}
	else
	{
		a->p.y = *y;
		a->p.x = *x;
	}
}

void	change_map(t_all *a, int x, int y, unsigned int *cnt_cmd)
{
	a->m.map[y][x] = '0';
	a->m.map[a->p.y][a->p.x] = 'P';
	(*cnt_cmd)++;
}

int	key_press(int keycode, t_all *a)
{
	static unsigned int	cnt_cmd;
	static t_element	t;

	save_p_pos(a, &(t.x), &(t.y), 1);
	if (keycode == KEY_W)
		a->p.y--;
	else if (keycode == KEY_S)
		a->p.y++;
	else if (keycode == KEY_A)
		a->p.x--;
	else if (keycode == KEY_D)
		a->p.x++;
	else if (keycode == KEY_ESC)
		exit(0);
	if (a->m.map[a->p.y][a->p.x] == '1')
		save_p_pos(a, &(t.x), &(t.y), 0);
	else
		change_map(a, t.x, t.y, &cnt_cmd);
	view_map(a->v, a->cp_m, a->i);
	view_element(a->v, a->m, a->i);
	print_cnt(a, cnt_cmd);
	return (0);
}
