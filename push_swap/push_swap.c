/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 09:20:14 by juha              #+#    #+#             */
/*   Updated: 2022/09/21 16:38:33 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static void	change_idx(t_stack *stack)
{
	int				cnt;
	t_stack_node	*node;

	node = stack->a_top;
	cnt = stack->total;
	while (cnt--)
	{
		node->origin_num = node->idx;
		node = node->next;
	}
}

int	main(int argc, char **argv)
{
	t_stack	stack;	
	t_ret	*ret;

	ret = NULL;
	check_error(argc, argv);
	init_stack(&stack, argc, argv);
	stack.total = stack.cnt_a;
	if (is_sorting(stack.a_top, stack.cnt_a, A))
		return (0);
	change_idx(&stack);
	sort_stack(&stack, &ret, argc);
	print_cmd(ret);
	return (0);
}
