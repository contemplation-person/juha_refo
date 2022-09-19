/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 15:48:14 by juha              #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/09/19 20:59:12 by juha             ###   ########seoul.kr  */
=======
/*   Updated: 2022/09/18 02:48:56 by juha             ###   ########seoul.kr  */
>>>>>>> a9ea8d6c5df5b8fd8d7b29dda483962db8e046d3
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

<<<<<<< HEAD
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
=======
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
>>>>>>> a9ea8d6c5df5b8fd8d7b29dda483962db8e046d3
	if (cnt < 4)
		return ;
	i = 0;
	divide_std = cnt / 3;
	while (i++ < cnt)
	{
<<<<<<< HEAD
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
=======
		if (cnt == 2)
			two_b(stack, stack->b_top, ret, B);
		else if (cnt == 3)
			three(stack, stack->b_top, ret, B);
		else
			p(stack, ret, PA);
>>>>>>> a9ea8d6c5df5b8fd8d7b29dda483962db8e046d3
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
<<<<<<< HEAD
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
=======
	while (i++ < cnt)
	{
		if (stack->b_top->idx >= num.max - pivot)
			p(stack, ret, PA);
		if (stack->a_top->idx >= num.max - pivot * 2)
>>>>>>> a9ea8d6c5df5b8fd8d7b29dda483962db8e046d3
		{
			p(stack, ret, PA);
			r(stack, ret, RA);
			reverse_second++;
		}
<<<<<<< HEAD
		else if (stack->a_top->idx < num.min + divide_std * 2)
			p(stack, ret, PB);
=======
>>>>>>> a9ea8d6c5df5b8fd8d7b29dda483962db8e046d3
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
<<<<<<< HEAD
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
=======
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
>>>>>>> a9ea8d6c5df5b8fd8d7b29dda483962db8e046d3
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
