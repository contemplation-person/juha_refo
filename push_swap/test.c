/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 18:55:11 by juha              #+#    #+#             */
/*   Updated: 2022/09/13 00:47:37 by juha             ###   ########seoul.kr  */
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

void	print_cmd(t_ret *ret)
{
	while (ret)
	{
		if (ret->cmd == PA)
			printf("pa\n");
		else if (ret->cmd == PB)
			printf("pb\n");
		else if (ret->cmd == RA)
			printf("ra\n");
		else if (ret->cmd == RB)
			printf("rb\n");
		else if (ret->cmd == RR)
			printf("rr\n");
		else if (ret->cmd == RRA)
			printf("rra\n");
		else if (ret->cmd == RRB)
			printf("rrb\n");
		else if (ret->cmd == RRR)
			printf("rrr\n");
		else if (ret->cmd == SA)
			printf("sa\n");
		else if (ret->cmd == SB)
			printf("sb\n");
		else if (ret->cmd == SS)
			printf("ss\n");
		ret = ret->next;
	}
}