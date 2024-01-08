/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hardcode.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 15:48:14 by juha              #+#    #+#             */
/*   Updated: 2023/01/16 01:12:21 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	two(t_stack *stack, t_stack_node *top, t_s_name name)
{
	if (is_sorting(top, 2, name))
		return ;
	s(stack, SA * name);
}

void	three(t_stack *stack, t_stack_node *top, t_s_name name)
{
	if (is_sorting(top, 3, name))
		return ;
	else if (top->idx < top->next->idx)
	{
		if (top->idx < top->next->next->idx)
		{
			s(stack, SA * name);
			r(stack, RA * name);
		}
		else
			rr(stack, RRA * name);
	}
	else
	{
		if (top->next->idx < top->next->next->idx && \
		top->idx > top->next->next->idx)
			r(stack, RA * name);
		else
		{
			s(stack, SA * name);
			if (top->idx > top->next->next->idx)
				rr(stack, RRA * name);
		}
	}
}

int	find_node(t_stack_node *top, int idx)
{
	int				pos_min;
	t_stack_node	*node;

	pos_min = 0;
	node = top;
	while (node->idx != idx)
	{
		pos_min++;
		node = node->next;
	}
	return (pos_min);
}

void	four(t_stack *stack, t_stack_node *top)
{
	int	pos_min;

	pos_min = find_node(top, 0);
	if (pos_min == 1)
		s(stack, SA);
	if (pos_min == 2)
	{
		rr(stack, RRA);
		rr(stack, RRA);
	}
	if (pos_min == 3)
		rr(stack, RRA);
	p(stack, PB);
	three(stack, stack->a_top, A);
	p(stack, PA);
}

void	five(t_stack *stack, t_stack_node *top)
{
	int				pos_min;

	pos_min = find_node(top, 4);
	if (pos_min == 1)
		s(stack, SA);
	if (pos_min == 2)
	{
		r(stack, RA);
		r(stack, RA);
	}
	if (pos_min == 3)
	{
		rr(stack, RRA);
		rr(stack, RRA);
	}
	if (pos_min == 4)
		rr(stack, RRA);
	p(stack, PB);
	four(stack, stack->a_top);
	p(stack, PA);
	r(stack, RA);
}
