/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 11:30:29 by juha              #+#    #+#             */
/*   Updated: 2022/08/24 05:07:52 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>

typedef enum e_cmd
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
	NEXT = 1,
	PREV = -1,
	FRONT = 1,
	REAR = 2,
}t_cmd;

typedef struct s_stack_node
{
	int					num;
	unsigned int		idx;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}t_stack_node;

typedef struct s_stack
{
	unsigned int	counting_node;
	t_stack_node	*stack;
}t_stack;

typedef struct s_ret
{
	int				cmd;
	struct s_ret	*next;
	struct s_ret	*prev;
}t_ret;

typedef enum e_bool
{
	TRUE = -1,
	FALSE = 0,
}t_bool;

t_bool	check_error(int argc, char **argv);
t_bool	write_error_message(char *message);

#endif