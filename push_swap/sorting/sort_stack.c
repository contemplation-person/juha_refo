/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 15:48:14 by juha              #+#    #+#             */
/*   Updated: 2022/09/17 15:24:26 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	b_to_a(t_stack *stack, t_ret **ret, t_num num, int cnt);

/* quick */
void	a_to_b(t_stack *stack, t_ret **ret, t_num num, int cnt)
{
	int		pivot_big;
	int		pivot_small;
	t_num	temp;

	if (is_sorting (stack->a_top, stack->cnt_a, stack->total))
		return ;
	if (cnt < 4)
	{
		if (!is_sorting(stack->a_top, 3, A))
		{
			if (cnt == 3)
				three(stack, stack->a_top, ret, A);
			if (cnt == 2)
				two(stack, stack->a_top, ret, A);
		}
		return ;
	}
	pivot_big = num.max - (cnt / 3);
	pivot_small = num.min + (cnt / 3);
	while (cnt--)
	{
		if (stack->a_top->idx >= pivot_big)
			r(stack, ret, RA);
		else if (stack->a_top->idx >= pivot_small)
			p(stack, ret, PB);
		else
		{
			p(stack, ret, PB);
			r(stack, ret, RB);
		}
	}
	temp.max = num.max;
	temp.min = pivot_big;
	b_to_a(stack, ret, temp, cnt / 3);
	temp.max = pivot_big - 1;
	temp.min = pivot_small;
	b_to_a(stack, ret, temp, cnt - (cnt / 3 * 2));
	temp.max = pivot_small - 1;
	temp.max = num.min;
	b_to_a(stack, ret, temp, cnt / 3);
}

void	b_to_a(t_stack *stack, t_ret **ret, t_num num, int cnt)
{
	int		pivot_big;
	int		pivot_small;
	t_num	temp;

	if (cnt < 4)
	{
		if (!is_sorting(stack->a_top, 3, A))
		{
			if (cnt == 3)
				three_b(stack, stack->a_top, ret, A);
			else if (cnt == 2)
				two_b(stack, stack->a_top, ret, A);
			else
				p(stack, ret, PA);
		}
		return ;
	}
	/*ㅇㅏ래  로로직  다다시  짜짜라라*/
	pivot_big = num.max - (cnt / 3);
	pivot_small = num.min + (cnt / 3);
	if (is_sorting (stack->a_top, stack->cnt_a, stack->total))
		return ;
	while (cnt--)
	{
		if (stack->a_top->idx >= pivot_big)
			r(stack, ret, RA);
		else if (stack->a_top->idx >= pivot_small)
			p(stack, ret, PB);
		else
		{
			p(stack, ret, PB);
			r(stack, ret, RB);
		}
	}
	temp.max = num.max;
	temp.min = pivot_big;
	b_to_a(stack, ret, temp, cnt / 3);
	temp.max = pivot_big - 1;
	temp.min = pivot_small;
	b_to_a(stack, ret, temp, cnt - (cnt / 3 * 2));
	temp.max = pivot_small - 1;
	temp.max = num.min;
	b_to_a(stack, ret, temp, cnt / 3);
}

void	else_sorting(t_stack *stack, t_ret **ret)
{
	t_num	num;
	int		i;

	num.max = stack->total;
	num.min = 0;
	i = 0;
	while (i++ < stack->total)
	{
		stack->a_top->origin_num = stack->a_top->idx;
		stack->a_top = stack->a_top->next;
	}
	if (is_sorting(stack->a_top, stack->total, A))
		return ;
	a_to_b(stack, ret, num, stack->total);
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
