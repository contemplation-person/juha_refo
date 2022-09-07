/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hardcode.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 15:48:14 by juha              #+#    #+#             */
/*   Updated: 2022/09/07 16:41:32 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_bool	is_sorting(t_stack_node *top, int stack_size)
{
	int				std;
	int				i;
	t_stack_node	*node;

	i = 0;
	std = -1;
	node = top;
	while (i < stack_size)
	{
		if (node->idx < std)
			return (FALSE);
		std = node->idx;
		node = node->next;
	}
}

// void	two(t_stack *stack, t_stack_node **top, t_ret *ret, t_cmd cmd)
// {
	
// }

// void	tree(t_stack *stack, t_stack_node **top, t_ret *ret, t_cmd cmd)
// {
	
// }
