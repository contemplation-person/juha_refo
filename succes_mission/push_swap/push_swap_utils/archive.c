/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   archive.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 03:31:31 by juha              #+#    #+#             */
/*   Updated: 2023/01/10 04:13:59 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	init(t_archive *archive)
{
	archive->cmd = NULL;
	archive->next = NULL;
}

t_archive	*new_archive(t_cmd cmd)
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
	if (start == target)
	{
		start = target->next;
	}
	else
	{
		target_prev->next = target->next;
	}
	free(target);
	return (start);
}