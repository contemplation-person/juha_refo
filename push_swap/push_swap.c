/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 09:20:14 by juha              #+#    #+#             */
/*   Updated: 2022/08/24 00:34:18 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_stack(t_stack a, t_stack b, int argc)
{
	int	i;
	int	size;

	size = argc - 1;
	a.stack = malloc(sizeof(int) * (size));
	if (!a.stack)
	{
		write_error_message("malloc failed\n");
		exit(1);
	}
	b.stack = malloc(sizeof(int) * (size));
	if (!b.stack)
	{
		write_error_message("malloc failed\n");
		exit(1);
	}
	i = 0;
	while (i < size)
	{
		a.stack[i] = -1;
		b.stack[i] = -1;
	}
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	check_error(argc, argv);
	create_stack(a, b, argc);

	return ();
}
