/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 11:30:29 by juha              #+#    #+#             */
/*   Updated: 2022/07/13 14:52:07 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>

typedef enum s_cmd
{
	PA = 1,
	SA,
	RA,
	RRA,
	PB = 10,
	SB,
	RB,
	RRB,
	RRR = 100,
	RR,
	SS,
}t_cmd;

typedef enum s_bool
{
	TRUE = -1,
	FALSE = 0,
}t_bool;

typedef struct s_stack
{
	int	*stack;
	int	p_pos;
	int	size;
}t_stack;

#endif