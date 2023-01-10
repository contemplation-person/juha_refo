/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_b.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:57:34 by juha              #+#    #+#             */
/*   Updated: 2023/01/10 23:58:01 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack_node	*push(t_stack *stack, t_s_name name, t_stack_node *target)
{
	if (name == A && stack->cnt_a == 0)
		stack->a_top = target;
	else if (name == B && stack->cnt_b == 0)
		stack->b_top = target;
	else if (name == A)
	{
		target->next = stack->a_top;
		target->prev = stack->a_top->prev;
		stack->a_top->prev->next = target;
		stack->a_top->prev = target;
		stack->a_top = target;
	}
	else
	{
		target->next = stack->b_top;
		target->prev = stack->b_top->prev;
		stack->b_top->prev->next = target;
		stack->b_top->prev = target;
		stack->b_top = target;
	}
	if (name == A)
		stack->cnt_a++;
	else if (name == B)
		stack->cnt_b++;
	return (target);
}

t_bool	pb(t_stack *stack, t_archive *archive)
{
	if (!(stack->cnt_a))
		return (FALSE);
	push(stack, B, pop(stack, A));
	add_back_archive(archive, PB);
	return (TRUE);
}

t_bool	rb(t_stack *stack, t_archive *archive)
{
	if (stack->cnt_b == 0 || stack->cnt_b == 1)
		return (FALSE);
	stack->b_top = stack->b_top->next;
	add_back_archive(archive, RB);
	return (TRUE);
}

t_bool	rrb(t_stack *stack, t_archive *archive)
{
	if (stack->cnt_b == 0 || stack->cnt_b == 1)
		return (FALSE);
	stack->b_top = stack->b_top->prev;
	add_back_archive(archive, RRB);
	return (TRUE);
}

t_bool	sb(t_stack *stack, t_archive *archive)
{
	t_stack_node	*temp_next;
	t_stack_node	*top;
	t_stack_node	*target;
	t_stack_node	*temp_prev;

	if (stack->cnt_b == 0 || stack->cnt_b == 1)
		return (FALSE);
	target = stack->b_top->next;
	temp_next = target->next;
	top = stack->b_top;
	temp_prev = top->prev;
	stack->b_top = target;
	target->next = top;
	top->prev = target;
	target->prev = temp_prev;
	temp_prev->next = target;
	temp_next->prev = top;
	top->next = temp_next;
	add_back_archive(archive, SB);
	return (TRUE);
}
