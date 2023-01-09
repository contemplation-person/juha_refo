/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hardcode.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 15:48:14 by juha              #+#    #+#             */
/*   Updated: 2023/01/10 03:30:03 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	two(t_stack *stack, t_s_name name, t_archive *archive)
{
	t_stack_node	*target_node;
	int				cnt;

	if (name == A)
	{
		target_node = stack->a_top;
		cnt = stack->cnt_a;
	}
	else
	{
		target_node = stack->b_top;
		cnt = stack->cnt_b;
	}
	if (is_sorting(target_node, cnt, name))
		return ;
	if (name == A)
		sa(stack, archive);
	else
		sb(stack, archive);
}

void	three(t_stack *stack, t_archive *archive)
{
	if (is_sorting(stack->a_top, stack->cnt_a, A))
		return ;
	if (stack->a_top->idx < stack->a_top->next->idx)
	{
		if (stack->a_top->idx < stack->a_top->next->next->idx)
		{
			sa(stack, archive);
			ra(stack, archive);
		}
		else
			rra(stack, archive);
	}
	else
	{
		if (stack->a_top->next->idx < stack->a_top->next->next->idx && \
		stack->a_top->idx > stack->a_top->next->next->idx)
			ra(stack, archive);
		else
		{
			sa(stack, archive);
			if (stack->a_top->idx > stack->a_top->next->next->idx)
				rra(stack, archive);
		}
	}
}

int	find_node(t_stack_node *top, int idx)
{
	int				pos_min;
	t_stack_node	*node;

	pos_min = 0;
	node = top;
	while (node->idx != idx)
	{
		pos_min++;
		node = node->next;
	}
	return (pos_min);
}

void	four(t_stack *stack, t_stack_node *top, t_archive *archive)
{
	int	pos_min;

	pos_min = find_node(top, 0);
	if (pos_min == 1)
		sa(stack, archive);
	if (pos_min == 2)
	{
		rra(stack, archive);
		rra(stack, archive);
	}
	if (pos_min == 3)
		rra(stack, archive);
	pb(stack, archive);
	three(stack, archive);
	pa(stack, archive);
}

void	five(t_stack *stack, t_stack_node *top, t_archive *archive)
{
	int				pos_min;

	pos_min = find_node(top, 4);
	if (pos_min == 1)
		sa(stack, archive);
	if (pos_min == 2)
	{
		ra(stack, archive);
		ra(stack, archive);
	}
	if (pos_min == 3)
	{
		rra(stack, archive);
		rra(stack, archive);
	}
	if (pos_min == 4)
		rra(stack, archive);
	pb(stack, archive);
	four(stack, stack->a_top, archive);
	pa(stack, archive);
	ra(stack, archive);
}
