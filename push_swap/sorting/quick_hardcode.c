/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hardcode.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 15:48:14 by juha              #+#    #+#             */
/*   Updated: 2022/09/08 15:40:24by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	two_b(t_stack *stack, t_stack_node *top, t_ret **ret, t_s_name name)
{
	if (!is_sorting(top, 2, name))
		s(stack, ret, SA * name);
	p(stack, ret, PA);
	p(stack, ret, PA);
}

static void	case_2(t_stack *stack, t_ret **ret, t_s_name name)
{
	if (name == A)
	{
		r(stack, ret, RB);
		s(stack, ret, SB);
	}
	p(stack, ret, PA);
	p(stack, ret, PA);
	if (name == A)
	{
		rr(stack, ret, RRB);
		p(stack, ret, PA);
	}
}

static void	case_3(t_stack *stack, t_ret **ret, t_s_name name)
{
	if (name == A)
	{
		s(stack, ret, SB);
		p(stack, ret, PA);
	}
	else if (name == B)
		p(stack, ret, PA);
	s(stack, ret, SB);
	p(stack, ret, PA);
	p(stack, ret, PA);
}

void	three_b(t_stack *stack, t_stack_node *top, t_ret **ret, t_s_name name)
{
	t_stack_node	*b;

	if (is_sorting(b, 3, A))
		case_2(stack, ret, A);
	else if (is_sorting(b, 3, B))
		case_2(stack, ret, B);
	else if (b->idx < b->next->idx && b->next->idx > b->next->next->idx \
				&& b->idx < b->next->next->idx)
		case_3(stack, ret, A);
	else if (b->idx > b->next->idx && b->idx > b->next->next->idx \
				&& b->next->idx < b->next->next->idx)
		case_3(stack, ret, B);
	else if (b->idx < b->next->idx && b->next->idx > b->next->next->idx \
				&& b->idx > b->next->next->idx)
		case_3(stack, ret, 3);
	else
	{
		r(stack, ret, RB);
		s(stack, ret, SB);
		p(stack, ret, PA);
		rr(stack, ret, RRB);
		p(stack, ret, PA);
		p(stack, ret, PA);
	}
}
