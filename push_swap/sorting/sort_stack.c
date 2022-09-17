/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 15:48:14 by juha              #+#    #+#             */
/*   Updated: 2022/09/17 16:59:09 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	b_to_a(t_stack *stack, t_ret **ret);

/* quick */
void	a_to_b(t_stack *stack, t_ret **ret, t_num num, int cnt)
{
	int		pivot_big;
	int		pivot_small;
	t_num	temp;
	int		i;

	if (is_sorting (stack->a_top, stack->cnt_a, stack->total))
		return ;
	view(*stack);
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
	pivot_small = num.min + (cnt / 3);
	pivot_big = pivot_small + (cnt / 3);
	while (cnt--)
	{
		if (stack->a_top->idx < pivot_small)
		{
			p(stack, ret, PB);
			r(stack, ret, RB);
		}
		else if (stack->a_top->idx < pivot_big)
			p(stack, ret, PB);
		else
			r(stack, ret, RA);
	}
	temp.max = num.max;
	temp.min = pivot_big;
	a_to_b(stack, ret, temp, cnt - pivot_big);
	temp.max = pivot_big;
	temp.min = pivot_small;
	a_to_b(stack, ret, temp, temp.max - temp.min);
	temp.max = pivot_small;
	temp.max = num.min;
	a_to_b(stack, ret, temp, temp.max - temp.min);
}

void	b_to_a(t_stack *stack, t_ret **ret, int pivot)
{
	if (pivot == b_stack)
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
