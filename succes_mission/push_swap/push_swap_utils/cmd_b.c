/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_b.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:57:34 by juha              #+#    #+#             */
/*   Updated: 2023/01/14 10:45:48 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack_node	*push(t_stack *stack, t_s_name name, t_stack_node *pop_target)
{
	t_stack_node	*top_node;

	if (name == A)
		top_node = stack->a_top;
	else
		top_node = stack->b_top;
	if (name == A && !top_node)
		stack->a_top = pop_target;
	if (name == B && !top_node)
		stack->b_top = pop_target;
	else
	{
		top_node->prev->next = pop_target;
		pop_target->prev = top_node->prev;
		top_node->prev = pop_target;
		pop_target->next = top_node;
	}
	if (name == A)
		stack->cnt_a++;
	else if (name == B)
		stack->cnt_b++;
	return (pop_target);
}

t_bool	pb(t_stack *stack, t_archive **archive)
{
	if (!(stack->cnt_a))
		return (FALSE);
	push(stack, B, pop(stack, A));
	add_back_archive(archive, PB);
	return (TRUE);
}

t_bool	rb(t_stack *stack, t_archive **archive)
{
	if (stack->cnt_b < 2)
		return (FALSE);
	stack->b_top = stack->b_top->next;
	add_back_archive(archive, RB);
	return (TRUE);
}

t_bool	rrb(t_stack *stack, t_archive **archive)
{
	if (stack->cnt_b < 2)
		return (FALSE);
	stack->b_top = stack->b_top->prev;
	add_back_archive(archive, RRB);
	return (TRUE);
}

t_bool	sb(t_stack *stack, t_archive **archive)
{
	t_stack_node	*temp_next;
	t_stack_node	*top;
	t_stack_node	*target;
	t_stack_node	*temp_prev;

	if (stack->cnt_b < 2)
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