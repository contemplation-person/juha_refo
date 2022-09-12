/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 15:48:14 by juha              #+#    #+#             */
/*   Updated: 2022/09/12 13:08:36 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
void	b_to_a(t_stack *stack, t_ret **ret, int max, int min);

void	a_to_b(t_stack *stack, t_ret **ret, int max, int min)
{
	static int	std;
	int			i;
	int			pivot;

	pivot = (max - min + 1) / 2;
	if (std == stack->total || max == min)
		return ;
	i = min;
	while (i++ < max)
	{
		if (std == stack->a_top->next->idx)
			s(stack, ret, SA);
		if (std == stack->a_top->idx)
		{
			r(stack, ret, RA);
			std++;
			min++;
			continue ;
		}
		p(stack, ret, PB);
		if (pivot > stack->b_top->idx)
			r(stack, ret, RB);
	}
	b_to_a(stack, ret, max, min + pivot);
	b_to_a(stack, ret, min + pivot - 1, min);
}

void	b_to_a(t_stack *stack, t_ret **ret, int max, int min)
{
	int			i;
	int			pivot;

	pivot = (max - min + 1) / 2;
	i = min;
	if (max - min == 1)
	{
		p(stack, ret, PA);
		return ;
	}
	while (i++ < max)
	{
		if (pivot < stack->b_top->idx)
			p(stack, ret, PA);
		else
			r(stack, ret, RB);
	}
	while (i-- > min)
	{
		rr(stack, ret, RRB);
		p(stack, ret, PA);
	}
	a_to_b(stack, ret, max, min + pivot);
	a_to_b(stack, ret, min + pivot - 1, min);
}

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

void	else_sorting(t_stack *stack, t_ret **ret)
{
	if (is_sorting(stack->a_top, stack->cnt_a, A))
		return ;
	a_to_b(stack, ret, stack->total, 0);
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
