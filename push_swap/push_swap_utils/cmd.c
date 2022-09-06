/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:57:34 by juha              #+#    #+#             */
/*   Updated: 2022/09/06 19:13:19 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// void	pa(t_stack *stack)
// {
// 	t_stack_node	*next;

// 	if (stack->cnt_b == 0)
// 		return ;
// 	next = stack->a_top;

// 	stack->a_top = stack->b_top;
// 	stack->b_top = stack->b_top->next;
// 	stack->a_top->next = next;
// 	next->prev = stack->a_top;
// 	if (stack->cnt_a == 0)
// 		stack->b_rear = stack->a_top;
// 	if (stack->cnt_b == 1)
// 		stack->b_rear = NULL;
// 	stack->cnt_a++;
// 	stack->cnt_b--;
// }

// void	pb(t_stack *stack, t_ret *ret)
// {
// 	if (stack->cnt_a == 0)
// 		return ;
// 	new_ret(ret, PB);
// 	stack->b_top = stack->a_top;
// 	if (stack->cnt_b == 0)
// 	{
// 		stack->b_top->next = NULL;
// 		stack->b_top->prev = NULL;
// 	}
// 	if (stack->cnt_a == 1)
// 	{
// 		stack->a_top = stack->a_top->next;
// 		stack->b_top->next->prev = stack->b_top;
// 	}
// 	stack->cnt_a--;
// 	stack->cnt_b++;
// }

void	r(t_stack *stack, t_ret *ret, t_cmd cmd)
{
	if ((cmd == RA && stack->cnt_a == 0) || \
		(cmd == RB && stack->cnt_b == 0))
		return ;
	new_ret(ret, cmd);
	if (cmd == RA)
		stack->a_top = stack->a_top->next;
	if (cmd == RB)
		stack->b_top = stack->b_top->next;
}

void	rr(t_stack *stack, t_ret *ret, t_cmd cmd)
{
	if ((cmd == RRA && stack->cnt_a == 0) || \
		(cmd == RRB && stack->cnt_b == 0))
		return ;
	new_ret(ret, cmd);
	if (cmd == RRA)
		stack->a_top = stack->a_top->prev;
	if (cmd == RRB)
		stack->b_top = stack->b_top->prev;
}

// void	s(t_stack_node *node)
// {

// }