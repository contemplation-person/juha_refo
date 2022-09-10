/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 15:48:14 by juha              #+#    #+#             */
/*   Updated: 2022/09/10 19:34:16 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// void	go_to_b(t_stack *stack, t_ret **ret, int cnt)
// {
// 	if (stack->cnt_a == 0)
// 		return ;
// 	p(stack, ret, PB);
// 	if (stack->a_top->idx == cnt / 2)
// 		r(stack, ret, RB);
// }

// void	go_to_a(t_stack *stack, t_ret **ret, int cnt)
// {
// 	if (stack->cnt_b == 0)
// 		return ;
// 	p(stack, ret, PA);
// 	if (stack->a_top->idx == cnt / 2)
// 		r(stack, ret, RA);
// }
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

// void	else_sorting(t_stack *stack, t_ret **ret, int cnt)
// {
// 	int	i;

// 	i = 0;
// 	while (stack->cnt_a == 3)
// 	{
// 		if (stack->a_top->idx < cnt / 3)
// 		{
// 			p(stack, ret, PB);
// 			r(stack, ret, RB);
// 		}
// 		else if (stack->a_top->idx < cnt * 2 / 3)
// 			p(stack, ret, PB);
// 		else
// 			r(stack, ret, RA);
// 	}
// }

void	sort_stack(t_stack *stack, t_ret **ret, int argc)
{
	int	cnt_num;

	cnt_num = argc - 1;
	if (cnt_num > 5)
		// else_sorting(stack, ret);
	;
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
