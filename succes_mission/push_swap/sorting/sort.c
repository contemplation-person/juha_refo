/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 16:25:22 by juha              #+#    #+#             */
/*   Updated: 2023/01/11 00:06:46 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

#include <stdio.h>
void	print_stack(t_stack *stack)
{
	t_stack_node *a;
	t_stack_node *b;
	a = stack->a_top;
	b = stack->b_top;
	printf("stack a\tstack b\n");
	int total;
	total = stack->cnt_a > stack->cnt_b ? stack->cnt_a : stack->cnt_b;
	for(int i = 0; i < total; i++)
	{
		if (stack->a_top && i < stack->cnt_a)
		{
			printf("%d", a->idx);
			a = a->next;
		}
		if (stack->b_top && i < stack->cnt_b)
		{
			printf("\t%d", b->idx);
			b = b->next;
		}
		printf("\n");
	}
}

//chunk = 0.000000053 * x * x + 0.03 * x + 14.5;
void	a_to_b(t_stack *stack, t_archive *archive)
{
	t_stack_node	*temp;
	float			chunk;

	chunk = 0.000000053 * stack->total * stack->total + 0.03 * stack->total + 14.5;
	while (stack->cnt_a)
	{
		temp = stack->a_top;
		if (temp->idx > chunk + stack->cnt_b)
			ra(stack, archive);
		else if (temp->idx > stack->cnt_b)
		{
			pb(stack, archive);
			rb(stack, archive);
		}
		else
			pb(stack, archive);

		sleep(1);
		printf("temp : %d, stack->cnt_a : %d, stack->cnt_b %d\n", temp->idx, stack->cnt_a, stack->cnt_b);
		print_stack(stack);
	}
}

void	sort(t_stack *stack, t_archive *archive)
{

	//if (stack->cnt_a == stack->total && 
	//	is_sorting(stack->a_top, stack->cnt_a, A))
	//	break ;
	a_to_b(stack, archive);
	//b_to_a(stack, archive);
	print_stack(stack);
}

void	sort_stack(t_stack *stack, t_archive *archive)
{
	if (stack->total > 5)
		sort(stack, archive);
	else if (stack->total == 1)
		exit(0);
	else if (stack->total == 2)
		two(stack, A, archive);
	else if (stack->total == 3)
		three(stack, archive);
	else if (stack->total == 4)
		four(stack, stack->a_top, archive);
	else if (stack->total == 5)
		five(stack, stack->a_top, archive);
}
