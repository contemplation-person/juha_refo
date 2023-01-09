/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 11:30:29 by juha              #+#    #+#             */
/*   Updated: 2023/01/10 04:13:15 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
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

typedef struct s_archive
{
	t_cmd					cmd;
	struct s_cmd_archive	*next;
}t_archive;


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

void			sort_stack(t_stack *stack, t_archive *archive);

void			two(t_stack *stack, t_s_name name, t_archive *archive);
void			three(t_stack *stack, t_archive *archive);
void			four(t_stack *stack, t_stack_node *top, t_archive *archive);
void			five(t_stack *stack, t_stack_node *top, t_archive *archive);

t_bool			pa(t_stack *stack, t_archive *archive);
t_bool			ra(t_stack *stack, t_archive *archive);
t_bool			rra(t_stack *stack, t_archive *archive);
t_bool			sa(t_stack *stack, t_archive *archive);

t_bool			pb(t_stack *stack, t_archive *archive);
t_bool			rb(t_stack *stack, t_archive *archive);
t_bool			rrb(t_stack *stack, t_archive *archive);
t_bool			sb(t_stack *stack, t_archive *archive);

void			init_stack(t_stack *stack, int argc, char **argv);
t_bool			is_sorting(t_stack_node *top, int stack_size, t_s_name name);

t_bool			check_error(int argc, char **argv);

void			write_error(char *error_file);
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
#endif