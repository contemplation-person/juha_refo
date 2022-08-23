/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 09:20:14 by juha              #+#    #+#             */
/*   Updated: 2022/08/24 05:06:28 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack *a, t_stack *b, int argc, char **argv)
{
	a->counting_node = 0;
	b->counting_node = 0;
	b->stack = NULL;
	while ((a->counting_node)++ < argc - 1)
	{
		
	}
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	t_ret	*ret;

	check_error(argc, argv);
	init_stack(&a, &b, argc, argv);
	return ();
}
