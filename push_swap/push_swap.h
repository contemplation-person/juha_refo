/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 11:30:29 by juha              #+#    #+#             */
/*   Updated: 2022/08/24 00:17:00 by juha             ###   ########seoul.kr  */
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
}t_cmd;

typedef enum e_bool
{
	TRUE = -1,
	FALSE = 0,
}t_bool;

typedef struct s_stack_info
{
	int	*stack;
	int	front;
	int	rear;
}t_stack;


t_bool	check_error(int argc, char **argv);
t_bool	write_error_message(char *message);

#endif