/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 18:55:11 by juha              #+#    #+#             */
/*   Updated: 2022/09/10 16:30:23 by juha             ###   ########seoul.kr  */
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
	printf("--------------a---------------top-------------b-----------------------\n");
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
			printf("| index : %d | origin : %d \n", b->idx, b->origin_num);
			cnt_b--;
			b = b->next;
			i++;
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