/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 15:48:14 by juha              #+#    #+#             */
/*   Updated: 2022/09/14 19:47:46 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	b_to_a(t_stack *stack, t_ret **ret, t_num num, int cnt);

void	a_to_b(t_stack *stack, t_ret **ret, t_num num, int cnt)
{
	static int	std;
	t_num		save;
	int			pivot;
	int			temp;

	if (std == stack->total)
		return ;
	pivot = (num.max + num.min) / 2;
	while (cnt--)
	{
		if (std == stack->a_top->next->idx)
			s(stack, ret, SA);
		if (std == stack->a_top->idx)
		{
			r(stack, ret, RA);
			num.min++;
			std++;
			continue ;
		}
		if (std <= stack->a_top->idx)
		{
			p(stack, ret, PB);
			if (pivot < stack->b_top->idx)
				r(stack, ret, RB);
		}
	}
	if (std == stack->total)
		return ;
	// view(*stack);
	save.min = num.min;
	save.max = pivot;
	b_to_a(stack, ret, save, pivot);
}

void	b_to_a(t_stack *stack, t_ret **ret, t_num num, int cnt)
{
	t_num		save;
	int			pivot;
	int			j;

	if (stack->cnt_b < 1)
		return ;
	pivot = (num.max + num.min) / 2;
	j = 0;
	while (num.min <= stack->b_top->idx && stack->b_top->idx <= num.max)
	{
		if (stack->cnt_b == 0)
			return ;
		if (pivot < stack->b_top->idx)
			p(stack, ret, PA);
		else
		{
			r(stack, ret, RB);
			j++;
		}
	}
	while (j++ < cnt)
	{
		rr(stack, ret, RRB);
		p(stack, ret, PA);
	}
	// view(*stack);
	save.min = num.min;
	save.max = pivot;
	a_to_b(stack, ret, save, pivot);
	save.min = pivot + 1;
	save.max = num.max;
	a_to_b(stack, ret, save, num.max - pivot);
}

/*
// void	quick_hardcode(t_stack *stack, t_stack_node *top, \
// t_ret **ret, t_s_name name)
// {
// 	int	a;
// 	int	b;
// 	int	c;

// 	if (is_sorting(top, 3, name))
// 		return ;
// 	a = top->idx;
// 	b = top->next->idx;
// 	c = top->next->next->idx;
// 	if (!((a < c && c < b) || (b < c && c < a)))
// 		s(stack, ret, SA * name);
// 	if (b < a && a < c)
// 		return ;
// 	r(stack, ret, RA * name);
// 	s(stack, ret, SA * name);
// 	rr(stack, ret, RRA * name);
// 	if ((b < c && c < a) || (c < b && b < a))
// 		s(stack, ret, SA * name);
// }

// void	rev_quick_hardcode(t_stack *stack, t_stack_node *top, \
// t_ret **ret, t_s_name name)
// {
// 	int	a;
// 	int	b;
// 	int	c;

// 	if (is_sorting(top, 3, name))
// 		return ;
// 	a = top->idx;
// 	b = top->next->idx;
// 	c = top->next->next->idx;
// 	if (!((c < a && a < b) || (b < a && a < c)))
// 		s(stack, ret, SA + name);
// 	if (b < c && c < a)
// 		return ;
// 	r(stack, ret, RA + name);
// 	s(stack, ret, SA + name);
// 	rr(stack, ret, RRA + name);
// 	if ((b < a && a < c) || (a < b && b < c))
// 		s(stack, ret, SA + name);
// }
*/

void	else_sorting(t_stack *stack, t_ret **ret)
{
	t_num num;

	num.max = stack->total;
	num.min = 0;
	if (is_sorting(stack->a_top, stack->total, A))
		return ;
	a_to_b(stack, ret, num, num.max);
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
