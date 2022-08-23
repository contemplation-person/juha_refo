/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 00:10:53 by juha              #+#    #+#             */
/*   Updated: 2022/08/24 02:28:39 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	insert_cmd(t_ret **ret, t_cmd cmd)
{
	t_ret	*temp;

	temp = molloc(sizeof(t_ret));
	if (!temp)
	{
		write_error_message("malloc failed\n");
		exit(1);
	}
	temp->cmd = cmd;
	if (!(*ret))
		*ret = temp;
	else
	{
		(*ret)->next = temp;
		temp->prev = *ret;
	}
}

int	search_next_idx(t_stack stack, t_cmd target)
{
	unsigned int	ret;

	if (target == FRONT)
	{
		ret = stack.front;
		while (stack.stack[ret] == -1)
			ret++;
		ret = ret % stack.size;
		ret += stack.size;
	}
	else
	{
		ret = stack.rear;
		while (stack.stack[ret] != -1)
			ret++;
		ret = ret % stack.size;
	}
	return (ret);
}

t_bool	swap(t_stack target, t_ret *ret)
{
	unsigned int	front;
	unsigned int	*stack;
	unsigned int	temp;
	int				i;

	if (front % target.size == target.rear % target.size)
		return (FALSE);
	stack = target.stack;
	front = target.front;
	temp = stack[front];
	i = 1;
	while (stack[front - i] != -1)
		i++;
	stack[front] = stack[front - i];
	stack[front - i] = temp;
	if (target.name == 'a')
		insert_cmd(ret, SA);
	else if (target.name == 'b')
		insert_cmd(ret, SB);
	return (TRUE);
}

t_bool	push(t_stack push, t_stack pop, t_ret *ret)
{
	int	new_push_front;
	int	new_pop_front;

	if (pop.front % pop.size == pop.rear % pop.size)
		return (FALSE);
	new_pop_front = pop.front;
	new_push_front = search_next_idx(push, FRONT);
	while (pop.stack[pop.front])
	push.stack[push.front] = pop.stack[pop.front];
	push.front = push.front % push.size;
	pop.front = pop.front % pop.size;
}
