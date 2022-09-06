/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ret.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:40:12 by juha              #+#    #+#             */
/*   Updated: 2022/09/06 17:05:55 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	new_ret(t_ret *ret, t_cmd cmd)
{
	t_ret	*new;
	t_ret	*temp;

	new = malloc(sizeof(t_ret));
	if (!new)
		exit(write_error_message());
	new->cmd = cmd;
	if (!ret)
	{
		ret = new;
		return ;
	}
	temp = ret;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
	new->prev = temp;
}
