/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 15:48:14 by juha              #+#    #+#             */
/*   Updated: 2022/09/11 17:55:39 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
void	go_to_a(t_stack *stack, t_ret **ret, int cnt, int pivot);

void	go_to_b(t_stack *stack, t_ret **ret, int max, int min)
{
	int	cnt;
	int	pivot;

	cnt = max - min + 2;
	if (max - min < 2)
	{
		if (max - min < 2)
			quick_hardcode(stack, stack->a_top, ret, A);
		if (max - min < 1)
			two(stack, stack->a_top, ret, A);
		while (--cnt)
			r(stack, ret, RA);
		return ;
	}
	pivot = (max - min) / 3;
	while (--cnt)
	{
		if (stack->a_top->idx < pivot)
		{
			p(stack, ret, PB);
			r(stack, ret, RB);
		}
		else if (stack->a_top->idx < pivot * 2)
			p(stack, ret, PB);
		else
			r(stack, ret, RA);
	}
	cnt = pivot * 2 + min;
	while (cnt++ < max)
	{
		rr(stack, ret, RRA);
		p(stack, ret, PB);
	}
	go_to_a(stack, ret, max, min + pivot * 2);
	go_to_a(stack, ret, min + pivot * 2 - 1, min + pivot);
	go_to_a(stack, ret, min + pivot - 1, min);
}

void	go_to_a(t_stack *stack, t_ret **ret, int max, int min)
{
	int	cnt;
	int	pivot;

	cnt = max - min + 2;
	if (max - min < 2)
	{
		if (max - min < 2)
			quick_hardcode(stack, stack->b_top, ret, B);
		if (max - min < 1)
			two(stack, stack->b_top, ret, B);
		while (--cnt)
			p(stack, ret, PB);
		return ;
	}
	pivot = (max - min) / 3;
	while (--cnt)
	{
		if (stack->b_top->idx > pivot)
		{
			p(stack, ret, PA);
			r(stack, ret, RA);
		}
		else if (stack->b_top->idx > pivot * 2)
			p(stack, ret, PA);
		else
			r(stack, ret, RB);
	}
	cnt = pivot * 2 + min;
	while (cnt++ < max)
	{
		rr(stack, ret, RRB);
		p(stack, ret, PA);
	}
	// 여기 방향 고쳐!!!
	go_to_a(stack, ret, max, min + pivot * 2);
	go_to_a(stack, ret, min + pivot * 2 - 1, min + pivot);
	go_to_a(stack, ret, min + pivot - 1, min);
}

void	quick_hardcode(t_stack *stack, t_stack_node *top, \
t_ret **ret, t_s_name name)
{
	int	a;
	int	b;
	int	c;

	if (is_sorting(top, 3, name))
		return ;
	a = top->idx;
	b = top->next->idx;
	c = top->next->next->idx;
	if (!((a < c && c < b) || (b < c && c < a)))
		s(stack, ret, SA * name);
	if (b < a && a < c)
		return ;
	r(stack, ret, RA * name);
	s(stack, ret, SA * name);
	rr(stack, ret, RRA * name);
	if ((b < c && c < a) || (c < b && b < a))
		s(stack, ret, SA * name);
}

void	rev_quick_hardcode(t_stack *stack, t_stack_node *top, \
t_ret **ret, t_s_name name)
{
	int	a;
	int	b;
	int	c;

	if (is_sorting(top, 3, name))
		return ;
	a = top->idx;
	b = top->next->idx;
	c = top->next->next->idx;
	if (!((c < a && a < b) || (b < a && a < c)))
		s(stack, ret, SA + name);
	if (b < c && c < a)
		return ;
	r(stack, ret, RA + name);
	s(stack, ret, SA + name);
	rr(stack, ret, RRA + name);
	if ((b < a && a < c) || (a < b && b < c))
		s(stack, ret, SA + name);
}

void	else_sorting(t_stack *stack, t_ret **ret)
{
	if (is_sorting(stack->a_top, stack->cnt_a, A))
		return ;
	go_to_b(stack, ret, stack->cnt_a, stack->cnt_a / 3);
	// sort_3
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
