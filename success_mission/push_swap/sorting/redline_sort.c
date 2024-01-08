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

void	a_to_b(t_stack *stack)
{
	int		chunk;

	chunk = get_chunk(stack);
	while (stack->cnt_a)
	{
		if (stack->a_top->idx > chunk + stack->cnt_b)
			r(stack, RA);
		else if (stack->a_top->idx > stack->cnt_b)
			p(stack, PB);
		else
		{
			p(stack, PB);
			r(stack, RB);
		}
	}
}

void	b_to_a(t_stack *stack)
{
	int				std;
	int				direction;
	t_stack_node	*target_node;

	direction = 1;
	while (stack->cnt_b)
	{
		std = 0;
		target_node = get_target_node(stack, &std);
		direction = std < stack->cnt_b / 2;
		if (direction)
			do_rb_n_pa(stack, target_node);
		else
			do_rrb_n_pa(stack, target_node);
	}
}

void	red_sort(t_stack *stack)
{
	a_to_b(stack);
	b_to_a(stack);
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
