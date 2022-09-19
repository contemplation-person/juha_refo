/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 15:48:14 by juha              #+#    #+#             */
/*   Updated: 2022/09/19 20:59:12 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	divide_stack_a(t_stack *stack, t_ret **ret, t_num num, int cnt);

void	marge(t_stack *stack, t_ret **ret, t_num num, t_s_name type)
{
	if (type == A)
	{
		while (num.max--)
		{
			rr(stack, ret, RRA);
		}
		while (num.min--)
		{
			rr(stack, ret, RRB);
			p(stack, ret, PA);
		}
	}
	else
	{
		while (num.max--)
		{
			rr(stack, ret, RRA);
		}
		while (num.min--)
		{
			rr(stack, ret, RRB);
			p(stack, ret, PA);
		}
	}
}

void	bottom_b_stack_sort(t_stack *stack, t_ret **ret, t_num num, int cnt)
{
	int		i;
	int		divide_std;
	t_num	temp;

	if (cnt == 1)
		p(stack, ret, PA);
	else if (cnt == 2)
		two_b(stack, stack->b_top, ret, B);
	else if (cnt == 3)
		three_b(stack, ret);
	if (cnt < 4)
		return ;
	i = 0;
	divide_std = cnt / 3;
	while (i++ < cnt)
	{
		if (stack->b_top->idx > num.max - divide_std)
			p(stack, ret, PA);
		else if (stack->b_top->idx > num.max - divide_std * 2)
		{
			p(stack, ret, PA);
			r(stack, ret, RA);
		}
		else
			r(stack, ret, RB);
	}
	temp.max = divide_std;
	temp.min = cnt - divide_std * 2;
	marge(stack, ret, temp, B);
	divide_stack_a(stack, ret, num, cnt);
}

void	top_b_stack_sort(t_stack *stack, t_ret **ret, t_num num, int cnt)
{
	int		i;
	int		divide_std;
	t_num	temp;

	if (cnt == 1)
		p(stack, ret, PA);
	else if (cnt == 2)
		two_b(stack, stack->b_top, ret, B);
	else if (cnt == 3)
		three_b(stack, ret);
	if (cnt < 4)
		return ;
	divide_std = cnt / 3;
	i = 0;
	while (i++ < cnt)
	{
		if (stack->b_top->idx > num.max - divide_std)
			p(stack, ret, PA);
		else if (stack->b_top->idx > num.max - divide_std * 2)
		{
			p(stack, ret, PA);
			r(stack, ret, RA);
		}
		else
			r(stack, ret, RB);
	}
	temp.max = divide_std;
	temp.min = cnt - divide_std * 2;
	marge(stack, ret, temp, A);
	divide_stack_a(stack, ret, num, cnt);
}

void	divide_stack_a(t_stack *stack, t_ret **ret, t_num num, int cnt)
{
	int		divide_std;
	int		i;
	t_num	temp;

	if (cnt == 2)
		two(stack, stack->a_top, ret, A);
	else if (cnt == 3)
		three(stack, stack->a_top, ret, A);
	if (cnt < 4)
		return ;
	divide_std = cnt / 3;
	i = 0;
	while (i++ < cnt)
	{
		if (stack->a_top->idx < num.min + divide_std)
		{
			p(stack, ret, PB);
			r(stack, ret, RB);
		}
		else if (stack->a_top->idx < num.min + divide_std * 2)
			p(stack, ret, PB);
		else
			r(stack, ret, RA);
	}
	temp.max = num.max;
	temp.min = num.min + divide_std * 2;
	// view(*stack);
	divide_stack_a(stack, ret, num, cnt - divide_std * 2);
	temp.max = num.min + divide_std * 2 - 1;
	temp.min = num.min + divide_std;
	top_b_stack_sort(stack, ret, temp, divide_std);
	temp.max = num.min + divide_std - 1;
	temp.min = num.min;
	bottom_b_stack_sort(stack, ret, temp, divide_std);
}

void	sort_stack(t_stack *stack, t_ret **ret, int argc)
{
	int		cnt_num;
	t_num	num;

	num.max = stack->total;
	num.min = 0;
	cnt_num = argc - 1;
	if (is_sorting(stack->a_top, stack->total, A))
		return ;
	else if (cnt_num > 5)
		divide_stack_a(stack, ret, num, stack->total);
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
