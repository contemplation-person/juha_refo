/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 09:20:14 by juha              #+#    #+#             */
/*   Updated: 2023/01/16 15:28:52 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_bool	r_cmd(t_stack *stack, char *cmd)
{
	if (!ft_strncmp("ra", cmd, 2)
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
	else
		return (FALSE);
	return (TRUE);
}

static t_bool	common_cmd(t_stack *stack, char *cmd)
{
	if (r_cmd(stack, cmd))
		return (TRUE);
	if (!ft_strncmp("pa", cmd, 2)
		&& ft_strlen("pa") == ft_strlen(cmd) - 1)
		p(stack, PA);
	else if (!ft_strncmp("pb", cmd, 2)
		&& ft_strlen("pb") == ft_strlen(cmd) - 1)
		p(stack, PB);
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

t_bool	dual_cmd(t_stack *stack, char *cmd)
{
	if (!ft_strncmp("rrr", cmd, 3) \
		&& ft_strlen("rrr") == ft_strlen(cmd) - 1)
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
		return (FALSE);
	return (TRUE);
}

t_bool	do_cmd(t_stack *stack, char *cmd)
{
	if (dual_cmd(stack, cmd))
		return (TRUE);
	if (common_cmd(stack, cmd))
		return (TRUE);
	else
	{
		write(2, "ERROR\n", 6);
		return (FALSE);
	}
	return (TRUE);
}
