/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 16:25:22 by juha              #+#    #+#             */
/*   Updated: 2022/09/21 00:04:54 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	cnt_total_radix(int total, int *check_bin, int std)
{
	int	radix;

	radix = 1;
	*check_bin = 1;
	while (total)
	{
		if (total % std > 1)
			*check_bin = 0;
		radix++;
		total = total / std;
	}
	return (radix);
}

void	b_to_a(t_stack *stack, t_ret **ret, int radix, int std)
{
	int	cnt;

	cnt = stack->cnt_b;
	while (cnt--)
	{
		if (stack->b_top->idx % std == radix)
		{
			stack->b_top->idx /= std;
			p(stack, ret, PA);
		}
		else
			r(stack, ret, RB);
	}
}

void	n_nary(t_stack *stack, t_ret **ret, int cnt, int std)
{
	int	i;

	while (cnt--)
	{
		if (stack->a_top->idx % std == std - 1)
		{
			stack->a_top->idx /= std;
			r(stack, ret, RA);
		}
		else
			p(stack, ret, PB);
	}
	i = std - 1;
	while (i--)
		b_to_a(stack, ret, i, std);
}

void	binary(t_stack *stack, t_ret **ret, int cnt, int std)
{
	while (cnt--)
	{
		if (stack->a_top->idx % std == 1)
		{
			stack->a_top->idx /= std;
			r(stack, ret, RA);
		}
		else
			p(stack, ret, PB);
	}
	cnt = 2;
	while (cnt--)
	{
		b_to_a(stack, ret, cnt, 2);
	}
}

void	radix_sort(t_stack *stack, t_ret **ret)
{
	int	radix;
	int	check_bin;
	int	std;

	std = 5;
	radix = cnt_total_radix(stack->total - 1, &check_bin, std);
	while (--radix)
	{
		if (radix == 0 && check_bin == 1)
		{
			binary(stack, ret, stack->total, std);
		}
		else
		{
			n_nary(stack, ret, stack->total, std);
		}
	}
}

void	sort_stack(t_stack *stack, t_ret **ret, int argc)
{
	if (argc == 1 || argc == 2)
		exit(1);
	else if (is_sorting(stack->a_top, stack->total, A))
		exit(1);
	else if (argc > 6)
		radix_sort(stack, ret);
	else if (argc == 3)
		two(stack, stack->a_top, ret, A);
	else if (argc == 4)
		three(stack, stack->a_top, ret, A);
	else if (argc == 5)
		four(stack, stack->a_top, ret);
	else if (argc == 6)
		five(stack, stack->a_top, ret);
}
