/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   archive.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 03:31:31 by juha              #+#    #+#             */
/*   Updated: 2023/01/14 10:31:57 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_archive	*new_archive(t_cmd cmd)
{
	t_archive	*archive;

	archive = malloc(sizeof(t_archive));
	if (!archive)
		write_error(__FILE__);
	archive->cmd = cmd;
	archive->next = NULL;
	return (archive);
}

t_archive	*add_back_archive(t_archive *start, t_cmd cmd)
{
	t_archive	*temp;

	temp = start;
	if (!temp)
	{
		start = new_archive(cmd);
		return (start);
	}
	while (temp->next)
		temp = temp->next;
	temp->next = new_archive(cmd);
	return (temp->next);
}

t_archive	*del_archive(t_archive *start, t_archive *target_prev, \
						t_archive *target)
{
	if (!start || !target)
		return (NULL);
	if (!target_prev)
	{
		start = start->next;
		free(start);
	}
	else if (start == target)
		start = target->next;
	else
		target_prev->next = target->next;
	free(target);
	return (start);
}

void	print_archive(t_archive *archive)
{
	t_archive	*temp;

	temp = archive;
	while (temp)
	{
		if (temp->cmd == RA)
			write(1, "ra\n", 3);
		if (temp->cmd == RB)
			write(1, "rb\n", 3);
		else if (temp->cmd == RRA)
			write(1, "rra\n", 4);
		else if (temp->cmd == RRB)
			write(1, "rrb\n", 4);
		else if (temp->cmd == SA)
			write(1, "sa\n", 3);
		else if (temp->cmd == SB)
			write(1, "sb\n", 3);
		else if (temp->cmd == PA)
			write(1, "pa\n", 3);
		else if (temp->cmd == PB)
			write(1, "pa\n", 3);
		temp = temp->next;
	}
}
