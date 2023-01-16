/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redline_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 16:25:22 by juha              #+#    #+#             */
/*   Updated: 2023/01/16 12:14:06 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	b_to_a(t_stack *stack)
{
	int	chunk;
	int	x;

	x = get_chunk(stack);
	chunk = 0.000000053 * x * x + 0.03 * x + 14.5 + stack->cnt_b;
	while (stack->cnt_a)
	{
		if (stack->a_top->idx > chunk)
			r(stack, RA);
		else if (stack->a_top->idx < chunk)
		{
			p(stack, PB);
			r(stack, RB);
		}
		else
			p(stack, PB);
	}
}

void	a_to_b(t_stack *stack)
{
	int				std;
	int				direction;
	t_stack_node	*target_node;

	direction = RB;
	while (stack->cnt_b)
	{
		std = 0;
		target_node = get_target_node(stack, &std);
		direction = std > stack->cnt_b / 2;
		if (direction)
			do_rb_n_pa(stack, target_node);
		else
			do_rrb_n_pa(stack, target_node);
	}
}

void	red_sort(t_stack *stack)
{
	b_to_a(stack);
	a_to_b(stack);
}

void	sort_stack(t_stack *stack, int argc)
{
	if (argc > 5)
		red_sort(stack);
	else if (argc == 1)
		exit(0);
	else if (argc == 2)
		two(stack, stack->a_top, A);
	else if (argc == 3)
		three(stack, stack->a_top, A);
	else if (argc == 4)
		four(stack, stack->a_top);
	else if (argc == 5)
		five(stack, stack->a_top);
}