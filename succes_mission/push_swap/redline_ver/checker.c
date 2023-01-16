/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 09:20:14 by juha              #+#    #+#             */
/*   Updated: 2023/01/16 11:19:28 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_bool	common_cmd(t_stack *stack, char *cmd)
{
	if (!ft_strncmp("pa", cmd, 2)
		&& ft_strlen("pa") == ft_strlen(cmd) - 1)
		p(stack, PA);
	else if (!ft_strncmp("pb", cmd, 2)
		&& ft_strlen("pb") == ft_strlen(cmd) - 1)
		p(stack, PB);
	else if (!ft_strncmp("ra", cmd, 2)
		&& ft_strlen("ra") == ft_strlen(cmd) - 1)
		r(stack, RA);
	else if (!ft_strncmp("rb", cmd, 2)
		&& ft_strlen("rb") == ft_strlen(cmd) - 1)
		r(stack, RB);
	else if (!ft_strncmp("rra", cmd, 3)
		&& ft_strlen("rra") == ft_strlen(cmd) - 1)
		rr(stack, RRA);
	else if (!ft_strncmp("rrb", cmd, 3)
		&& ft_strlen("rrb") == ft_strlen(cmd) - 1)
		rr(stack, RRB);
	else if (!ft_strncmp("sa", cmd, 2)
		&& ft_strlen("sa") == ft_strlen(cmd) - 1)
		s(stack, SA);
	else if (!ft_strncmp("sb", cmd, 2)
		&& ft_strlen("sb") == ft_strlen(cmd) - 1)
		s(stack, SB);
	else
		return (FALSE);
	return (TRUE);
}

t_bool	do_cmd(t_stack *stack, char *cmd)
{
	if (common_cmd(stack, cmd))
		return (TRUE);
	else if (!ft_strncmp("rrr", cmd, 3) \
		&&	ft_strlen("rrr") == ft_strlen(cmd) - 1)
	{
		rr(stack, RRA);
		rr(stack, RRB);
	}
	else if (!ft_strncmp("rr", cmd, 2) \
		&& ft_strlen("rr") == ft_strlen(cmd) - 1)
	{
		r(stack, RA);
		r(stack, RB);
	}
	else if (!ft_strncmp("ss", cmd, 2) \
		&& ft_strlen("ss") == ft_strlen(cmd) - 1)
	{
		s(stack, SA);
		s(stack, SB);
	}
	else
	{
		write(2, "ERROR\n", 6);
		return (FALSE);
	}
	return (TRUE);
}

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
	// system("leaks push_swap");
	return (0);
}
