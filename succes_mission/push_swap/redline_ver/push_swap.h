/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 11:30:29 by juha              #+#    #+#             */
/*   Updated: 2023/01/16 15:13:13 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./push_swap_utils/get_next_line.h"
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>

typedef enum e_stack_name
{
	A = 1,
	B = 10,
}t_s_name;

typedef enum e_cheker
{
	SORTED,
	UNSORTED,
}t_checker;

typedef enum e_cmd
{
	PA = 1,
	SA,
	RA,
	RRA,
	PB = 11,
	SB,
	RB,
	RRB,
	SS = 122,
	RR,
	RRR,
}t_cmd;

typedef struct s_stack_node
{
	int					idx;
	int					origin_num;
	t_checker			checker;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}t_stack_node;

typedef struct s_stack
{
	int				cnt_a;
	int				cnt_b;
	int				total;
	int				std;
	t_stack_node	*a_top;
	t_stack_node	*b_top;
}t_stack;

typedef struct s_pos
{
	int	top;
	int	bottom;
}t_pos;

typedef struct s_num
{
	int	max;
	int	min;
}t_num;

typedef enum e_bool
{
	TRUE = -1,
	FALSE = 0,
}t_bool;

t_bool			push(t_stack_node **target, t_stack_node *src, int *size);
t_stack_node	*pop(t_stack_node **top, int *cnt_stack);
char			*ft_substr(char const *s, size_t start, size_t len);

int				cnt_total_radix(int total, int *check_bin, int std);
void			sort_stack(t_stack *stack, int argc);

void			two(t_stack *stack, t_stack_node *top, t_s_name name);
void			three(t_stack *stack, t_stack_node *top, t_s_name name);
void			four(t_stack *stack, t_stack_node *top);
void			five(t_stack *stack, t_stack_node *top);

void			p(t_stack *stack, t_cmd cmd);
void			r(t_stack *stack, t_cmd cmd);
void			s(t_stack *stack, t_cmd cmd);
void			rr(t_stack *stack, t_cmd cmd);

void			init_stack(t_stack *stack, int argc, char **argv);
t_bool			is_sorting(t_stack_node *top, int stack_size, t_s_name name);

t_bool			check_error(int argc, char **argv);

int				write_error_message(void);
t_bool			is_int_max(char *argv);
t_bool			is_duplicate(int argc, char **argv);
t_bool			is_wrong_input(char *argv);
t_bool			check_error(int argc, char **argv);

size_t			change_size_t(const char *str);
size_t			ft_strlen(const char	*s);
long			ft_atoi(const char	*str);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
char			**ft_split(char const *s, char c);

char			**make_char_pp(int argc, char **argv);
int				cnt_split_str(char **argv);
void			change_idx(t_stack *stack);

t_stack_node	*get_target_node(t_stack *stack, int *std);
int				get_chunk(t_stack *stack);
void			do_rb_n_pa(t_stack *stack, t_stack_node *target);
void			do_rrb_n_pa(t_stack *stack, t_stack_node *target);

#endif