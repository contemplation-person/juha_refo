/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 09:20:14 by juha              #+#    #+#             */
/*   Updated: 2022/09/13 17:48:31 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>
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
	sort_stack(&stack, &ret, argc);
	print_cmd(ret);
	view(stack);
	system("leaks a.out");
	return (0);
}
