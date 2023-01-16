/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 09:20:14 by juha              #+#    #+#             */
/*   Updated: 2023/01/16 15:24:07 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_stack(t_stack *stack)
{
	char	*cmd;

	while (42)
	{
		cmd = get_next_line(STDIN_FILENO);
		if (!cmd)
			break ;
		if (!do_cmd(stack, cmd))
			return ;
		free(cmd);
	}
	if (stack->cnt_a == stack->total \
	&& is_sorting(stack->a_top, stack->cnt_a, A))
		write(STDOUT_FILENO, "OK\n", 3);
	else
		write(STDOUT_FILENO, "KO\n", 3);
}

int	main(int argc, char **v)
{
	t_stack	stack;	
	char	**argv;

	argv = make_char_pp(argc, v);
	argc = cnt_split_str(argv);
	check_error(argc, argv);
	init_stack(&stack, argc, argv);
	if (is_sorting(stack.a_top, stack.cnt_a, A))
	{
		write(STDOUT_FILENO, "OK\n", 3);
		return (0);
	}
	change_idx(&stack);
	check_stack(&stack);
	return (0);
}
