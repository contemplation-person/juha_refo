/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ret.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:40:12 by juha              #+#    #+#             */
/*   Updated: 2022/09/21 15:31:32 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	new_ret(t_ret **ret, t_cmd cmd)
{
	t_ret	*new;
	t_ret	*temp;

	new = malloc(sizeof(t_ret));
	if (!new)
		exit(write_error_message());
	new->cmd = cmd;
	if (!(*ret))
	{
		(*ret) = new;
		return ;
	}
	temp = (*ret);
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
	new->prev = temp;
}

void	print_cmd(t_ret *ret)
{
	while (ret)
	{
		if (ret->cmd == PA)
			write(1, "pa\n", 3);
		else if (ret->cmd == PB)
			write(1, "pb\n", 3);
		else if (ret->cmd == RA)
			write(1, "ra\n", 3);
		else if (ret->cmd == RB)
			write(1, "rb\n", 3);
		else if (ret->cmd == RR)
			write(1, "rr\n", 3);
		else if (ret->cmd == RRA)
			write(1, "rra\n", 4);
		else if (ret->cmd == RRB)
			write(1, "rrb\n", 4);
		else if (ret->cmd == RRR)
			write(1, "rrr\n", 4);
		ret = ret->next;
	}
}
