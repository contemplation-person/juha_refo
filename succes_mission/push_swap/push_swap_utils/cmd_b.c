/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_b.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:57:34 by juha              #+#    #+#             */
/*   Updated: 2023/01/10 01:59:58 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// b->a
t_bool	pb(t_stack *stack, t_archive *archive)
{
	t_stack_node	*pop_node;

	if (!(stack->cnt_a))
		return (FALSE);
	pop_node = stack->a_top;
	pop_node->prev->next = pop_node->next;
	pop_node->next->prev = pop_node->prev;
	if (stack->cnt_b == 0)
	{
		stack->b_top = pop_node;
		pop_node->prev = pop_node;
		pop_node->next = pop_node;
	}
	else
	{
		pop_node->next = stack->b_top->next;
		pop_node->prev = stack->b_top;
		stack->b_top = pop_node;
	}
	stack->cnt_b++;
	return (TRUE);
}

t_bool	rb(t_stack *stack, t_archive *archive)
{
	if (stack->cnt_b == 0 || stack->cnt_b == 1)
		return (FALSE);
	stack->b_top = stack->b_top->next;
	return (TRUE);
}

t_bool	rrb(t_stack *stack, t_archive *archive)
{
	if (stack->cnt_b == 0 || stack->cnt_b == 1)
		return (FALSE);
	stack->b_top = stack->b_top->prev;
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
	return (TRUE);
}
