/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 15:48:14 by juha              #+#    #+#             */
/*   Updated: 2022/09/20 00:19:31 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	divide(t_stack *stack, t_ret **ret, t_num num, int cnt)
{
	int		pivot;
	t_num	temp;

	if (cnt == 2)
		two_b(stack, stack->a_top, ret, A);
	else if (cnt == 3)
		three(stack, stack->a_top, ret, A);
	if (cnt < 4)
		return ;
	pivot = (num.max - num.min) / 3;
	while (cnt--)
	{
		if (stack->a_top->idx > num.max - pivot)
			r(stack, ret, RA);
		if (stack->a_top->idx > num.max - pivot * 2)
			p(stack, ret, PB);
		else
		{
			p(stack, ret, PB);
			r(stack, ret, RB);
		}
	}
	temp.max = num.max;
	temp.min = num.max - pivot;
	view(*stack);
	divide(stack, ret, temp, pivot);
	temp.max = num.max - pivot - 1;
	temp.min = num.max - pivot * 2;
	divide(stack, ret, temp, pivot);
	temp.max = num.max - pivot * 2 - 1;
	temp.min = num.min;
	divide(stack, ret, temp, cnt - pivot * 2);
	b_top_to_a(stack, ret, temp, pivot);
	b_bottom_to_a(stack, ret, temp, pivot);
}

void	sort_stack(t_stack *stack, t_ret **ret, int argc)
{
	int		cnt_num;
	t_num	num;

	num.max = stack->total;
	num.min = 0;
	cnt_num = argc - 1;
	if (cnt_num > 5)
		divide(stack, ret, num, stack->total);
	else if (cnt_num < 2)
		return ;
	else if (cnt_num == 2)
		two(stack, stack->a_top, ret, A);
	else if (cnt_num == 3)
		three(stack, stack->a_top, ret, A);
	else if (cnt_num == 4)
		four(stack, stack->a_top, ret);
	else
		five(stack, stack->a_top, ret);
}
