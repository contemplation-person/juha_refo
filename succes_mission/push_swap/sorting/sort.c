/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 16:25:22 by juha              #+#    #+#             */
/*   Updated: 2023/01/10 04:02:18 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_stack(t_stack *stack, t_archive *archive)
{
	if (stack->total > 5)
		sort(stack, archive);
	else if (stack->total == 1)
		exit(0);
	else if (stack->total == 2)
		two(stack, A, archive);
	else if (stack->total == 3)
		three(stack, archive);
	else if (stack->total == 4)
		four(stack, stack->a_top, archive);
	else if (stack->total == 5)
		five(stack, stack->a_top, archive);
}
