/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 16:00:51 by juha              #+#    #+#             */
/*   Updated: 2022/05/11 12:33:18 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H 

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>

typedef enum e_success
{
	ERROR = 0,
	SUCCESS,
	CONTINUE
}t_success;

typedef struct s_gnl_list
{
	ssize_t				fd;
	ssize_t				buf_len;
	char				*buf;
	struct s_gnl_list	*next;
	struct s_gnl_list	*prev;
}t_list;

t_success	get_list(t_list **head, t_list **fd_lst, int fd);
t_success	free_lst(t_list **fd_lst);
char		*get_next_line(int fd);

#endif
