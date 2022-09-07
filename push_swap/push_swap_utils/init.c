/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 14:56:29 by juha              #+#    #+#             */
/*   Updated: 2022/09/07 17:49:13 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_stack_node	*new_node(int num)
{
	t_stack_node	*ret;

	ret = malloc(sizeof(t_stack_node));
	if (!ret)
		exit(write_error_message());
	ret->next = ret;
	ret->prev = ret;
	ret->origin_num = num;
	return (ret);
}

static void	init_sort(t_stack_node **stack, t_stack_node **new)
{
	if ((*stack)->origin_num < (*new)->origin_num)
		(*new)->idx++;
	else
		(*stack)->idx++;
}

static void	add_init_add_back(t_stack_node **top, t_stack_node **new)
{
	t_stack_node	*prev;

	if (!(*top))
	{
		*top = *new;
		return ;
	}
	prev = *top;
	while (prev->next != *top)
	{
		init_sort(&prev, new);
		prev = prev->next;
	}
	init_sort(&prev, new);
	prev->next = *new;
	(*new)->prev = prev;
	(*new)->next = *top;
	(*top)->prev = *new;
}

void	init_stack(t_stack *stack, int argc, char **argv)
{
	int				i;
	t_stack_node	*new;

	i = 1;
	stack->a_top = NULL;
	stack->b_top = NULL;
	while (i < argc)
	{
		new = new_node(ft_atoi(argv[i]));
		add_init_add_back(&(stack->a_top), &new);
		i++;
	}
	stack->cnt_a = argc - 1;
	stack->cnt_b = 0;
}

t_bool	is_sorting(t_stack_node *top, int stack_size)
{
	int				std;
	int				i;
	t_stack_node	*node;

	i = 0;
	std = -1;
	node = top;
	while (i++ < stack_size)
	{
		if (node->idx < std)
			return (FALSE);
		std = node->idx;
		node = node->next;
	}
	return (TRUE);
}
