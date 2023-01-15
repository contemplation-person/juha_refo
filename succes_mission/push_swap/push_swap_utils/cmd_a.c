/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_a.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:57:34 by juha              #+#    #+#             */
/*   Updated: 2023/01/14 10:10:36 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack_node	*pop(t_stack *stack, t_s_name name)
{
	t_stack_node	*target;

	if (name == A)
		target = stack->a_top;
	else
		target = stack->b_top;
	if (!target)
		return (NULL);
	if (name == A && stack->cnt_a == 1)
		stack->a_top = NULL;
	else if (name == B && stack->cnt_b == 1)
		stack->b_top = NULL;
	else
	{
		if (name == A)
			stack->a_top = stack->a_top->next;
		if (name == B)
			stack->b_top = stack->b_top->next;
		target->prev->next = target->next;
		target->next->prev = target->prev;
		target->next = target;
		target->prev = target;
	}
	if (name == A)
		stack->cnt_a--;
	else if (name == B)
		stack->cnt_b--;
	return (target);
}

t_bool	pa(t_stack *stack, t_archive **archive)
{
	if (!(stack->cnt_b))
		return (FALSE);
	push(stack, A, pop(stack, B));
	add_back_archive(archive, PA);
	return (TRUE);
}

t_bool	ra(t_stack *stack, t_archive **archive)
{
	if (stack->cnt_a == 0 || stack->cnt_a == 1)
		return (FALSE);
	stack->a_top = stack->a_top->next;
	add_back_archive(archive, RA);
	return (TRUE);
}

t_bool	rra(t_stack *stack, t_archive **archive)
{
	if (stack->cnt_a == 0 || stack->cnt_a == 1)
		return (FALSE);
	stack->a_top = stack->a_top->prev;
	add_back_archive(archive, RRA);
	return (TRUE);
}

t_bool	sa(t_stack *stack, t_archive **archive)
{
	t_stack_node	*temp_next;
	t_stack_node	*top;
	t_stack_node	*target;
	t_stack_node	*temp_prev;

	if (stack->cnt_a == 0 || stack->cnt_a == 1)
		return (FALSE);
	target = stack->a_top->next;
	temp_next = target->next;
	top = stack->a_top;
	temp_prev = top->prev;
	stack->a_top = target;
	target->next = top;
	top->prev = target;
	target->prev = temp_prev;
	temp_prev->next = target;
	temp_next->prev = top;
	top->next = temp_next;
	add_back_archive(archive, SA);
	return (TRUE);
}
