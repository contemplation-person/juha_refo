/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 16:25:22 by juha              #+#    #+#             */
/*   Updated: 2022/09/24 19:55:16 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	b_to_a(t_stack *stack, int radix, int std)
{
	int	cnt;

	cnt = stack->cnt_b;
	while (cnt--)
	{
		if (stack->b_top->idx % std == radix)
		{
			stack->b_top->idx /= std;
			p(stack, PA);
		}
		else
			r(stack, RB);
	}
}

void	n_nary(t_stack *stack, int cnt, int std)
{
	int	i;

	while (cnt--)
	{
		if (stack->a_top->idx % std == std - 1)
		{
			stack->a_top->idx /= std;
			r(stack, RA);
		}
		else
			p(stack, PB);
	}
	i = std - 1;
	while (i--)
		b_to_a(stack, i, std);
}

void	binary(t_stack *stack, int cnt, int std)
{
	while (cnt--)
	{
		if (stack->a_top->idx % std == 1)
		{
			stack->a_top->idx /= std;
			r(stack, RA);
		}
		else
			p(stack, PB);
	}
	cnt = 2;
	while (cnt--)
	{
		b_to_a(stack, cnt, 2);
	}
}

void	radix_sort(t_stack *stack)
{
	int	radix;
	int	check_bin;
	int	std;

	std = 5;
	radix = cnt_total_radix(stack->total - 1, &check_bin, std);
	while (--radix)
	{
		if (is_sorting(stack->a_top, stack->cnt_a, A))
			return ;
		if (radix == 0 && check_bin == 1)
		{
			binary(stack, stack->total, std);
		}
		else
		{
			n_nary(stack, stack->total, std);
		}
	}
}

void	sort_stack(t_stack *stack, int argc)
{
	if (argc == 1 || argc == 2)
		exit(1);
	else if (is_sorting(stack->a_top, stack->total, A))
		exit(1);
	else if (argc > 6)
		radix_sort(stack);
	else if (argc == 3)
		two(stack, stack->a_top, A);
	else if (argc == 4)
		three(stack, stack->a_top, A);
	else if (argc == 5)
		four(stack, stack->a_top);
	else if (argc == 6)
		five(stack, stack->a_top);
}
