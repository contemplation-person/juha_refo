/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 09:20:14 by juha              #+#    #+#             */
/*   Updated: 2023/01/16 15:33:23 by juha             ###   ########seoul.kr  */
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

int	main(int argc, char **v)
{
	t_stack	stack;	
	char	**argv;

	if (argc == 1)
		return (0);
	argv = make_char_pp(argc, v);
	argc = cnt_split_str(argv);
	check_error(argc, argv);
	init_stack(&stack, argc, argv);
	if (is_sorting(stack.a_top, stack.cnt_a, A))
		return (0);
	change_idx(&stack);
	sort_stack(&stack, argc);
	return (0);
}
