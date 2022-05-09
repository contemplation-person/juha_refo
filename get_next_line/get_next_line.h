/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conteng <conteng@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 16:00:51 by juha              #+#    #+#             */
/*   Updated: 2022/05/10 01:54:25 by conteng          ###   ########seoul.kr  */
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

char	*get_next_line(int fd);

#endif
