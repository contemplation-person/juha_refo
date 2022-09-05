/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 18:55:11 by juha              #+#    #+#             */
/*   Updated: 2022/09/06 02:13:48 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	view(t_stack stack, int argc)
{
	int				i;
	int				cnt_a;
	int				cnt_b;
	t_stack_node	*a;
	t_stack_node	*b;

	i = 1;
	a = stack.a_top;
	b = stack.b_top;
	cnt_a = stack.cnt_a;
	cnt_b = stack.cnt_b;
	printf("--------------a---------------top-------------b--------------\n");
	while (i < argc)
	{
		if (cnt_a > 0)
		{
			printf("%d node| index : %d | origin : %d	", i, a->idx, a->origin_num);
			cnt_a--;
			a = a->next;
			i++;
		}
		else
			printf("%d node|										", i);
		if (cnt_b > 0)
		{
			printf("| index : %d | origin : %d \n", b->idx, a->origin_num);
			cnt_b--;
			b = b->next;
			i++;
		}
		printf("\n----------------------------------------------------------------------\n");
	}
}
