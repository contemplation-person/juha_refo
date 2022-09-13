/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 15:48:14 by juha              #+#    #+#             */
/*   Updated: 2022/09/13 17:43:54 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
void	b_to_a(t_stack *stack, t_ret **ret, int max, int min);

void	a_to_b(t_stack *stack, t_ret **ret, int max, int min)
{
	static int	std;
	int			i;
	int			pivot;
	int			temp;

	if (min >= max)
		return ;
	pivot = (max + min) / 2;
	i = min;
	temp = max + min;
	while (i++ < max)
	{
		if (std == stack->a_top->next->idx)
		{
			s(stack, ret, SA);
			view(*stack);
		}
		if (std == stack->a_top->idx)
		{
			r(stack, ret, RA);
			view(*stack);
			min++;
			std++;
			continue ;
		}
		p(stack, ret, PB);
		view(*stack);
		if (pivot < stack->b_top->idx)
			r(stack, ret, RB);
	}
	if (temp % 2)
	{
		if (std == stack->a_top->idx)
		{
			r(stack, ret, RA);
			view(*stack);
			min++;
			std++;
		}	
	}
	if (std == max)
		return ;
 	b_to_a(stack, ret, pivot, min);
	b_to_a(stack, ret, max, pivot + 1);
}

void	b_to_a(t_stack *stack, t_ret **ret, int max, int min)
{
	int			i;
	int			pivot;
	int			j;
	int			temp;

	pivot = (max + min) / 2;
	i = min;
	j = 0;
	temp = (max + min);
	while (i++ < max)
	{
		if (pivot < stack->b_top->idx)
			p(stack, ret, PA);
		else
		{
			r(stack, ret, RB);
			j++;
		}
		view(*stack);
	}
	if (temp % 2)
	{
		if (pivot < stack->b_top->idx)
			p(stack, ret, PA);
		else
		{
			r(stack, ret, RB);
			j++;
		}	
	}
	while (j-- > 0)
	{
		rr(stack, ret, RRB);
		p(stack, ret, PA);
		view(*stack);
	}
	view(*stack);
	a_to_b(stack, ret, pivot, min);
	a_to_b(stack, ret, max, pivot + 1);
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
	if (is_sorting(stack->a_top, stack->total, A))
		return ;
	a_to_b(stack, ret, stack->total, 0);
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
