/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:45:53 by juha              #+#    #+#             */
/*   Updated: 2023/01/16 12:13:05 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack_node	*get_target_node(t_stack *stack, int *std)
{
	t_stack_node	*top;

	top = stack->b_top;
	if (!top)
		return (NULL);
	while (top->idx == stack->cnt_b - 1)
	{
		(*std)++;
		top = top->next;
	}
	return (top);
}

int	get_chunk(t_stack *stack)
{
	if (stack->total <= 100)
		return (15);
	if (stack->total <= 500)
		return (30);
	if (stack->total <= 1000)
		return (45);
	if (stack->total <= 2000)
		return (65);
	if (stack->total <= 5000)
		return (150);
	return (200);
}

void	do_rb_n_pa(t_stack *stack, t_stack_node *target)
{
	t_stack_node	*b_top;

	b_top = stack->b_top;
	while (b_top == target)
		r(stack, RB);
	p(stack, PA);
}

void	do_rrb_n_pa(t_stack *stack, t_stack_node *target)
{
	t_stack_node	*b_top;

	b_top = stack->b_top;
	while (b_top == target)
		rr(stack, RB);
	p(stack, PA);
}
