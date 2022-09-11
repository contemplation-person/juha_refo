/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 15:48:14 by juha              #+#    #+#             */
/*   Updated: 2022/09/12 08:11:42 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
