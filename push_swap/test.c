/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 18:55:11 by juha              #+#    #+#             */
/*   Updated: 2022/09/15 18:00:03 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	view(t_stack stack)
{
	int				total = stack.total;
	int				a_cnt = stack.cnt_a;
	int				b_cnt = stack.cnt_b;
	t_stack_node	*a_node = stack.a_top;
	t_stack_node	*b_node = stack.b_top;

	printf("--------------a---------------top-------------b-----------------------\n");
	for(int i = 0, j = 1, k = 0;i + k < total;j++)
	{
		printf("%d node : ", j);
		if (i < a_cnt)
		{
			printf("idx[%d], origin : %d ", a_node->idx,a_node->origin_num);
			a_node = a_node->next;
			if (i < b_cnt)
			{
				printf("   | idx[%d], origin : %d", b_node->idx,b_node->origin_num);
				b_node = b_node->next;
				k++;
			}
			i++;
		}
		else
		{
			printf("                      | idx[%d], origin : %d", b_node->idx,b_node->origin_num);
			b_node = b_node->next;
			k++;
		}
		printf("\n----------------------------------------------------------------------\n");
	}
}


