/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 09:20:14 by juha              #+#    #+#             */
/*   Updated: 2022/09/08 19:34:20 by juha             ###   ########seoul.kr  */
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
	if (is_sorting(stack.a_top, stack.cnt_a, A))
		return (0);
	five(&stack, stack.a_top, &ret);
	while (ret)
	{
		printf("%d\n",ret->cmd);
		ret = ret->next;
	}
	view(stack, argc);
	// if (argc < 7)
	// {
		
	// }
	// sort_stack(&stack, ret);
	return (0);
}
