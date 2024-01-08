/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 14:56:29 by juha              #+#    #+#             */
/*   Updated: 2023/01/16 15:21:20 by juha             ###   ########seoul.kr  */
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
	ret->idx = 0;
	ret->checker = 0;
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

	i = 0;
	stack->a_top = NULL;
	stack->b_top = NULL;
	while (i < argc)
	{
		new = new_node(ft_atoi(argv[i]));
		add_init_add_back(&(stack->a_top), &new);
		i++;
	}
	stack->std = 0;
	stack->cnt_a = argc;
	stack->cnt_b = 0;
	stack->total = argc;
}
