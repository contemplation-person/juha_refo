/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 15:48:14 by juha              #+#    #+#             */
/*   Updated: 2022/09/15 23:23:47 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	b_to_a(t_stack *stack, t_ret **ret, t_num *num, int cnt);

/* quick */
void	a_to_b(t_stack *stack, t_ret **ret, t_num *num, int cnt)
{
	int	pivot_big;
	int	pivot_small;
	int	reverse;

	pivot_big = num->max + num->min * 2 / 3;
	reverse = 0;
	pivot_small = cnt / 3;
	if (cnt < 0 || is_sorting(stack->a_top, stack->cnt_a, stack->total))
		return ;
	while (cnt--)
	{
		if (pivot_big < stack->a_top->idx)
		{
			r(stack, ret, RA);
			reverse++;
			continue ;
		}
		p(stack, ret, PB);
		if (pivot_small >= stack->a_top->idx)
			r(stack, ret, RB);
	}
	cnt = 0;
	while (cnt++ < reverse)
	{
		rr(stack, ret, RRA);
		p(stack, ret, PB);
	}
	b_to_a(stack, ret, num, reverse);
	b_to_a(stack, ret, num, )
	b_to_a()
}

void	b_to_a(t_stack *stack, t_ret **ret, t_num *num, int cnt)
{

}

void	else_sorting(t_stack *stack, t_ret **ret)
{
	t_num	num;
	int		i;

	num.max = stack->total;
	num.min = 0;
	if (is_sorting(stack->a_top, stack->total, A))
		return ;

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
