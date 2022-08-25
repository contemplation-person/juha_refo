/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 16:00:51 by juha              #+#    #+#             */
/*   Updated: 2022/05/12 18:44:46 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H 

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
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

char		*get_next_line(int fd);
t_success	join_str(t_list **fd_lst, char **str, ssize_t read_len);
t_success	read_str(t_list **fd_lst, int fd);
char		*set_save(t_list **fd_lst, char **ret, ssize_t ret_len);
ssize_t		get_ret_len(t_list **fd_lst);

char		*ret_str(t_list **head, t_list **fd_lst);
void		*ft_memcpy(void *dst, const void *src, size_t n);
t_success	free_lst(t_list **head, t_list **fd_lst);
t_success	get_list(t_list **head, t_list **fd_lst, int fd);
void		set_fd_list(t_list **fd_lst, t_list *prev, int fd);

#endif
