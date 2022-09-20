/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 16:25:22 by juha              #+#    #+#             */
/*   Updated: 2022/09/20 18:38:13 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	cnt_total_radix(int total, int *check_bin)
{
	int	radix;

	radix = 0;
	while (total)
	{
		radix++;
		if (total % 3 == 1)
			*check_bin = 1;
		else
			*check_bin = 0;
		total = total / 3;
	}
	return (radix);
}

t_bool	is_persent_zero(t_stack stack)
{
	t_stack_node	*b;
	int				i;

	i = stack.cnt_b;
	b = stack.b_top;
	while (i--)
	{
		if (b->idx % 3 != 0)
			return (FALSE);
		b = b->next;
	}
	return (TRUE);
}

void	ternary(t_stack *stack, t_ret **ret, int cnt)
{
	while (cnt--)
	{
		if (stack->a_top->idx % 3 == 2)
		{
			stack->a_top->idx /= 3;
			r(stack, ret, RA);
		}
		else
			p(stack, ret, PB);
	}
	cnt = stack->cnt_b;
	while (stack->cnt_b)
	{
		if (is_persent_zero(*stack))
			break ;
		if (stack->b_top->idx % 3 == 1)
		{
			stack->a_top->idx /= 3;
			p(stack, ret, PA);
		}
	}
	while (stack->cnt_b)
	{
		stack->a_top->idx /= 3;
		p(stack, ret, PA);
	}
}

void	binary(t_stack *stack, t_ret **ret, int cnt)
{
	while (cnt--)
	{
		if (stack->a_top->idx % 2 == 1)
		{
			stack->a_top->idx /= 3;
			r(stack, ret, RA);
		}
		else
			p(stack, ret, PB);
	}
	cnt = stack->cnt_b;
	while (stack->cnt_b)
	{
		if (stack->b_top->idx % 3 == 0)
		{
			stack->a_top->idx /= 3;
			p(stack, ret, PA);
		}
	}
}

void	radix_sort(t_stack *stack, t_ret **ret)
{
	int	radix;
	int	check_bin;

	radix = cnt_total_radix(stack->total, &check_bin);
	while (radix--)
	{
		if (radix == 0 && check_bin == 1)
		{
			binary(stack, ret, stack->total);
		}
		else
		{
			ternary(stack, ret, stack->total);
		}
		ternary(stack, ret, stack->total);
	}
}

void	sort_stack(t_stack *stack, t_ret **ret, int argc)
{
	if (argc < 2)
		exit(1);
	else if (is_sorting(stack->a_top, stack->total, A))
		exit(1);
	else if (argc > 5)
		radix_sort(stack, ret);
	else if (argc == 3)
		three(stack, stack->a_top, ret, A);
	else if (argc == 4)
		four(stack, stack->a_top, ret);
	else if (argc == 5)
		five(stack, stack->a_top, ret);
}
