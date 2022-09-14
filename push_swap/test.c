/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 18:55:11 by juha              #+#    #+#             */
/*   Updated: 2022/09/14 19:46:51 by juha             ###   ########seoul.kr  */
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
			write(1, "pa\n", 3);
		else if (ret->cmd == PB)
			write(1, "pb\n", 3);
		else if (ret->cmd == RA)
			write(1, "ra\n", 3);
		else if (ret->cmd == RB)
			write(1, "rb\n", 3);
		else if (ret->cmd == RR)
			write(1, "rr\n", 3);
		else if (ret->cmd == RRA)
			write(1, "rra\n", 3);
		else if (ret->cmd == RRB)
			write(1, "rrb\n", 3);
		else if (ret->cmd == RRR)
			write(1, "rrr\n", 3);
		else if (ret->cmd == SA)
			write(1, "sa\n", 3);
		else if (ret->cmd == SB)
			write(1, "sb\n", 3);
		else if (ret->cmd == SS)
			write(1, "ss\n", 3);
		ret = ret->next;
	}
}
