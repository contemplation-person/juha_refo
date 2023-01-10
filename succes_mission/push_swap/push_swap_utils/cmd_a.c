/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_a.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:57:34 by juha              #+#    #+#             */
/*   Updated: 2023/01/10 13:00:33 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_bool	pa(t_stack *stack, t_archive *archive)
{
	t_stack_node	*pop_node;

	if (!(stack->cnt_b))
		return (FALSE);
	pop_node = stack->b_top;
	pop_node->prev->next = pop_node->next;
	pop_node->next->prev = pop_node->prev;
	if (stack->cnt_a == 0)
	{
		stack->a_top = pop_node;
		pop_node->prev = pop_node;
		pop_node->next = pop_node;
	}
	else
	{
		pop_node->next = stack->a_top->next;
		pop_node->prev = stack->a_top;
		stack->a_top = pop_node;
	}
	add_back_archive(archive, PA);
	stack->cnt_a++;
	return (TRUE);
}

t_bool	ra(t_stack *stack, t_archive *archive)
{
	if (stack->cnt_a == 0 || stack->cnt_a == 1)
		return (FALSE);
	stack->a_top = stack->a_top->next;
	add_back_archive(archive, RA);
	return (TRUE);
}

t_bool	rra(t_stack *stack, t_archive *archive)
{
	if (stack->cnt_a == 0 || stack->cnt_a == 1)
		return (FALSE);
	stack->a_top = stack->a_top->prev;
	add_back_archive(archive, RRA);
	return (TRUE);
}

t_bool	sa(t_stack *stack, t_archive *archive)
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
