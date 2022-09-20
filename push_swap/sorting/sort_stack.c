/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 15:48:14 by juha              #+#    #+#             */
/*   Updated: 2022/09/20 14:14:54 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	b_top_to_a(t_stack *stack, t_ret **ret, t_num num, int cnt)
{
	int		pivot;
	t_num	temp;
	int		small;

	if (cnt == 1)
		p(stack, ret, PA);
	else if (cnt == 2)
		two_b(stack, stack->b_top, ret, B);
	else if (cnt == 3)
		three_b(stack, ret);
	if (cnt < 4)
		return ;
	pivot = cnt / 3;
	small = 0;
	while (cnt--)
	{
		if (stack->b_top->idx > num.max - pivot)
			p(stack, ret, PA);
		else if (stack->b_top->idx > num.max - pivot * 2)
		{
			p(stack, ret, PA);
			r(stack, ret, RA);
		}
		else
		{
			r(stack, ret, RB);
			small++;
		}
	}
	temp.max = num.max;
	temp.min = num.max - pivot + 1;
	divide(stack, ret, temp, pivot);
	cnt = pivot;
	while (cnt--)
		rr(stack, ret, RRA);
	temp.max = num.max - pivot;
	temp.min = num.max - pivot * 2 + 1;
	divide(stack, ret, num, pivot);
	while (small--)
	{
		rr(stack, ret, RRB);
		p(stack, ret, PA);
	}
	temp.max = num.max - pivot * 2;
	temp.min = num.min;
	divide(stack, ret, num, small);
}

void	b_bottom_to_a(t_stack *stack, t_ret **ret, t_num num, int cnt)
{
	int		pivot;
	t_num	temp;
	int		small;

	if (cnt == 1)
		p(stack, ret, PA);
	else if (cnt == 2)
		two_b(stack, stack->b_top, ret, B);
	else if (cnt == 3)
		three_b(stack, ret);
	if (cnt < 4)
		return ;
	pivot = cnt / 3;
	small = 0;
	while (cnt--)
	{
		if (stack->b_top->idx > num.max - pivot)
			p(stack, ret, PA);
		else if (stack->b_top->idx > num.max - pivot * 2)
		{
			p(stack, ret, PA);
			r(stack, ret, RA);
		}
		else
		{
			r(stack, ret, RB);
			small++;
		}
	}
	temp.max = num.max;
	temp.min = num.max - pivot + 1;
	divide(stack, ret, temp, pivot);
	cnt = pivot;
	while (cnt--)
		rr(stack, ret, RRA);
	temp.max = num.max - pivot;
	temp.min = num.max - pivot * 2 + 1;
	divide(stack, ret, num, pivot);
	while (small--)
		p(stack, ret, PA);
	temp.max = num.max - pivot * 2;
	temp.min = num.min;
	divide(stack, ret, num, small);
}

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
	pivot = cnt / 3;
	while (cnt--)
	{
		if (stack->a_top->idx < num.min + pivot)
		{
			p(stack, ret, PB);
			r(stack, ret, RB);
		}
		if (stack->a_top->idx < num.min + pivot * 2)
			p(stack, ret, PB);
		else
			r(stack, ret, RA);
	}
	temp.max = num.max;
	temp.min = num.min + pivot * 2;
	view(*stack);
	divide(stack, ret, temp, cnt - pivot * 2);
	temp.max = num.min + pivot * 2 - 1;
	temp.min = num.min + pivot;
	divide(stack, ret, temp, pivot);
	temp.min = num.min + pivot - 1;
	temp.min = num.min;
	divide(stack, ret, temp, pivot);
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
