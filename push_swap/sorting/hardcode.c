/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hardcode.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 15:48:14 by juha              #+#    #+#             */
/*   Updated: 2022/09/21 16:38:53 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	two(t_stack *stack, t_stack_node *top, t_ret **ret, t_s_name name)
{
	if (is_sorting(top, 2, name))
		return ;
	s(stack, ret, SA * name);
}

void	three(t_stack *stack, t_stack_node *top, t_ret **ret, t_s_name name)
{
	if (is_sorting(top, 3, name))
		return ;
	else if (top->idx < top->next->idx)
	{
		if (top->idx < top->next->next->idx)
		{
			s(stack, ret, SA * name);
			r(stack, ret, RA * name);
		}
		else
			rr(stack, ret, RRA * name);
	}
	else
	{
		if (top->next->idx < top->next->next->idx && \
		top->idx > top->next->next->idx)
			r(stack, ret, RA * name);
		else
		{
			s(stack, ret, SA * name);
			if (top->idx > top->next->next->idx)
				rr(stack, ret, RRA * name);
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

void	four(t_stack *stack, t_stack_node *top, t_ret **ret)
{
	int	pos_min;

	pos_min = find_node(top, 0);
	if (pos_min == 1)
		s(stack, ret, SA);
	if (pos_min == 2)
	{
		rr(stack, ret, RRA);
		rr(stack, ret, RRA);
	}
	if (pos_min == 3)
		rr(stack, ret, RRA);
	p(stack, ret, PB);
	three(stack, stack->a_top, ret, A);
	p(stack, ret, PA);
}

void	five(t_stack *stack, t_stack_node *top, t_ret **ret)
{
	int				pos_min;

	pos_min = find_node(top, 4);
	if (pos_min == 1)
		s(stack, ret, SA);
	if (pos_min == 2)
	{
		r(stack, ret, RA);
		r(stack, ret, RA);
	}
	if (pos_min == 3)
	{
		rr(stack, ret, RRA);
		rr(stack, ret, RRA);
	}
	if (pos_min == 4)
		rr(stack, ret, RRA);
	p(stack, ret, PB);
	four(stack, stack->a_top, ret);
	p(stack, ret, PA);
	r(stack, ret, RA);
}
