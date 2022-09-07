/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hardcode.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 15:48:14 by juha              #+#    #+#             */
/*   Updated: 2022/09/07 18:50:29 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	two(t_stack *stack, t_stack_node *top_a, t_ret **ret)
{
	if (is_sorting(top_a, 2))
		return ;
	s(stack, ret, SA);
}

void	three(t_stack *stack, t_stack_node *top_a, t_ret **ret)
{
	if (is_sorting(top_a, 3))
		return ;
	else if (top_a->idx == 0)
	{
		rr(stack, ret, RRA);
		s(stack, ret, SA);
	}
	else if (top_a->idx == 1)
	{
		if (top_a->next->idx == 2)
			rr(stack, ret, RRA);
		else
			s(stack, ret, SA);
	}
	else
	{
		if (top_a->next->idx == 1)
		{
			s(stack, ret, SA);
			rr(stack, ret, RRA);
		}
		else
			r(stack, ret, RA);
	}
}
