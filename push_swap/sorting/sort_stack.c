/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 15:48:14 by juha              #+#    #+#             */
/*   Updated: 2022/09/18 02:48:56 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	b_top_to_a(t_stack *stack, t_ret **ret, t_num num, int cnt)
{
	int	i;
	int	pivot;
	int	reverse_second;
	int	reverse_third;

	i = 0;
	reverse_second = 0;
	reverse_third = 0;
	pivot = (num.max - num.min) / 3;
	if (cnt < 4)
	{
		if (cnt == 2)
			two_b(stack, stack->b_top, ret, B);
		else if (cnt == 3)
			three(stack, stack->b_top, ret, B);
		else
			p(stack, ret, PA);
		return ;
	}
	while (i++ < cnt)
	{
		if (stack->b_top->idx >= num.max - pivot)
			p(stack, ret, PA);
		if (stack->a_top->idx >= num.max - pivot * 2)
		{
			p(stack, ret, PA);
			r(stack, ret, RA);
			reverse_second++;
		}
		else
		{
			r(stack, ret, RB);
			reverse_third++;
		}
	}
	i = 0;
	while (i++ < reverse_second)
	{
		rr(stack, ret, RRA);
	}
	while (i++ < reverse_third)
	{
		rr(stack, ret, RRB);
		p(stack, ret, PA);
	}
}

void	b_bottom_to_a(t_stack *stack, t_ret **ret, t_num num, int cnt)
{
	int	i;
	int	pivot;
	int	reverse_second;
	int	reverse_third;

	if (cnt < 4)
	{
		if (cnt == 2)
			two_b(stack, stack->b_top, ret, B);
		else if (cnt == 3)
			three(stack, stack->b_top, ret, B);
		else
			p(stack, ret, PA);
		return ;
	}
	i = 0;
	reverse_second = 0;
	reverse_third = 0;
	pivot = (num.max - num.min) / 3;
	while (i++ < cnt)
	{
		if (stack->b_top->idx >= num.max - pivot)
			p(stack, ret, PA);
		if (stack->a_top->idx >= num.max - pivot * 2)
		{
			p(stack, ret, PA);
			r(stack, ret, RA);
			reverse_second++;
		}
		else
		{
			r(stack, ret, RB);
			reverse_third++;
		}
	}
	i = 0;
	while (i++ < reverse_second)
	{
		rr(stack, ret, RRA);
	}
	while (i++ < reverse_third)
	{
		rr(stack, ret, RRB);
		p(stack, ret, PA);
	}
}

void	divide(t_stack *stack, t_ret **ret, t_num num, int cnt)
{
	int		i;
	int		pivot;
	t_num	temp;

	if (cnt < 4)
		return ;
	i = 0;
	pivot = (num.max - num.min) / 3;
	while (i++ < cnt)
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

void	else_sorting(t_stack *stack, t_ret **ret)
{
	t_num	num;

	if (is_sorting(stack->a_top, stack->total, A))
		return ;
	num.max = stack->total;
	num.min = 0;
	divide(stack, ret, num, stack->total);
}

void	sort_stack(t_stack *stack, t_ret **ret, int argc)
{
	int	cnt_num;

	cnt_num = argc - 1;
	if (cnt_num > 5)
		else_sorting(stack, ret);
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
