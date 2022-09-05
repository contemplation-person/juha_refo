/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 11:30:29 by juha              #+#    #+#             */
/*   Updated: 2022/09/06 01:38:55 by juha             ###   ########seoul.kr  */
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
	int					idx;
	int					origin_num;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}t_stack_node;

typedef struct s_stack
{
	int				cnt_a;
	t_stack_node	*a_top;
	t_stack_node	*a_rear;
	int				cnt_b;
	t_stack_node	*b_top;
	t_stack_node	*b_rear;
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


void	view(t_stack stack, int argc);
void	init_stack(t_stack *stack, int argc, char **argv);

t_bool	check_error(int argc, char **argv);
t_bool	write_error_message(void);

int		write_error_message(void);
t_bool	is_int_max(char *argv);
t_bool	is_duplicate(int argc, char **argv);
t_bool	is_wrong_input(char *argv);
t_bool	check_error(int argc, char **argv);

size_t	change_size_t(const char *str);
size_t	ft_strlen(const char	*s);
long	ft_atoi(const char	*str);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	ft_bzero(void *s, size_t n);
#endif