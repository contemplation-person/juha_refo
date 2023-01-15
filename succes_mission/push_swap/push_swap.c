/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 09:20:14 by juha              #+#    #+#             */
/*   Updated: 2023/01/14 13:25:34 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	cnt_split_str(char **argv)
{
	int	i;

	if (!argv)
		return (0);
	i = 0;
	while (argv[i])
		i++;
	return (i);
}

int	main(int argc, char **argv)
{
	t_stack				stack;
	static t_archive	archive;

	//argv[1]번부터 돌려야함. 
	//"1 2 3"바꿔야함.
	check_error(argc, argv);
	init_stack(&stack, argc, argv);
	change_idx(&stack);
cmd_test(&stack, &archive);
	// if (is_sorting(stack.a_top, stack.cnt_a, A))
	// 	return (0);
	// sort_stack(&stack, &archive);


	// print_archive(&archive);
	// system("leaks push_swap");
	return (0);
}
