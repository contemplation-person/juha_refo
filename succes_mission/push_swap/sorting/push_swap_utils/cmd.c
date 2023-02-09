/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:57:34 by juha              #+#    #+#             */
/*   Updated: 2023/01/16 11:05:00 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	p(t_stack *stack, t_cmd cmd)
{
	if (cmd == PA && stack->cnt_b > 0)
	{
		if (push(&(stack->a_top), pop(&(stack->b_top), &(stack->cnt_b)), \
		&(stack->cnt_a)))
			write(1, "pa\n", 3);
	}
	else if (cmd == PB && stack->cnt_a > 0)
	{
		if (push(&(stack->b_top), pop(&(stack->a_top), &(stack->cnt_a)), \
		&(stack->cnt_b)))
			write(1, "pb\n", 3);
	}
	return ;
}

void	r(t_stack *stack, t_cmd cmd)
{
	if ((cmd == RA && stack->cnt_a == 0) || \
		(cmd == RB && stack->cnt_b == 0) || \
		(cmd == RA && stack->cnt_a == 1) || \
		(cmd == RB && stack->cnt_b == 1))
		return ;
	if (cmd == RA)
	{
		write(1, "ra\n", 3);
		stack->a_top = stack->a_top->next;
	}
	if (cmd == RB)
	{
		write(1, "rb\n", 3);
		stack->b_top = stack->b_top->next;
	}
}

void	rr(t_stack *stack, t_cmd cmd)
{
	if ((cmd == RRA && stack->cnt_a == 0) || \
		(cmd == RRB && stack->cnt_b == 0) || \
		(cmd == RRA && stack->cnt_a == 1) || \
		(cmd == RRB && stack->cnt_b == 1))
		return ;
	if (cmd == RRA)
	{
		write(1, "rra\n", 4);
		stack->a_top = stack->a_top->prev;
	}
	if (cmd == RRB)
	{
		write(1, "rrb\n", 4);
		stack->b_top = stack->b_top->prev;
	}
}

void	s(t_stack *stack, t_cmd cmd)
{
	t_stack_node	*swap_top;
	t_stack_node	*swap_next;
	t_stack_node	temp;

	if ((cmd == SA && stack->cnt_a == 0) || (cmd == SB && stack->cnt_b == 0) || \
		(cmd == SA && stack->cnt_a == 1) || \
		(cmd == SB && stack->cnt_b == 1))
		return ;
	if (cmd == SA)
	{
		write(1, "sa\n", 3);
		swap_top = stack->a_top;
		swap_next = stack->a_top->next;
	}
	else
	{
		write(1, "sb\n", 3);
		swap_top = stack->b_top;
		swap_next = stack->b_top->next;
	}
	temp = *swap_top;
	swap_top->idx = swap_next->idx;
	swap_top->origin_num = swap_next->origin_num;
	swap_next->idx = temp.idx;
	swap_next->origin_num = temp.origin_num;
}
