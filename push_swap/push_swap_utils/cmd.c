/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:57:34 by juha              #+#    #+#             */
/*   Updated: 2022/09/07 18:38:29 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	p(t_stack *stack, t_ret **ret, t_cmd cmd)
{
	if (cmd == PA && stack->cnt_b > 0)
	{
		if (push(&(stack->a_top), pop(&(stack->b_top), &(stack->cnt_b)), \
		&(stack->cnt_a)))
			new_ret(ret, cmd);
	}
	else if (cmd == PB && stack->cnt_a > 0)
	{
		if (push(&(stack->b_top), pop(&(stack->a_top), &(stack->cnt_a)), \
		&(stack->cnt_b)))
			new_ret(ret, cmd);
	}
	return ;
}

void	r(t_stack *stack, t_ret **ret, t_cmd cmd)
{
	if ((cmd == RA && stack->cnt_a == 0) || \
		(cmd == RB && stack->cnt_b == 0) || \
		(cmd == RA && stack->cnt_a == 1) || \
		(cmd == RB && stack->cnt_b == 1))
		return ;
	new_ret(ret, cmd);
	if (cmd == RA)
		stack->a_top = stack->a_top->next;
	if (cmd == RB)
		stack->b_top = stack->b_top->next;
}

void	rr(t_stack *stack, t_ret **ret, t_cmd cmd)
{
	if ((cmd == RRA && stack->cnt_a == 0) || \
		(cmd == RRB && stack->cnt_b == 0) || \
		(cmd == RRA && stack->cnt_a == 1) || \
		(cmd == RRB && stack->cnt_b == 1))
		return ;
	new_ret(ret, cmd);
	if (cmd == RRA)
		stack->a_top = stack->a_top->prev;
	if (cmd == RRB)
		stack->b_top = stack->b_top->prev;
}

void	s(t_stack *stack, t_ret **ret, t_cmd cmd)
{
	t_stack_node	*swap_top;
	t_stack_node	*swap_next;
	t_stack_node	temp;

	if ((cmd == SA && stack->cnt_a == 0) || \
		(cmd == SB && stack->cnt_b == 0) || \
		(cmd == SA && stack->cnt_a == 1) || \
		(cmd == SB && stack->cnt_b == 1))
		return ;
	new_ret(ret, cmd);
	if (cmd == SA)
	{
		swap_top = stack->a_top;
		swap_next = stack->a_top->next;
	}
	else
	{
		swap_top = stack->b_top;
		swap_next = stack->b_top->next;
	}
	temp = *swap_top;
	swap_top->idx = swap_next->idx;
	swap_top->origin_num = swap_next->origin_num;
	swap_next->idx = temp.idx;
	swap_next->origin_num = temp.origin_num;
}
