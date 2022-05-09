/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 16:00:51 by juha              #+#    #+#             */
/*   Updated: 2022/05/09 15:24:11 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_H 

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <sys/types.h>

typedef struct s_gnl_list
{
	ssize_t				fd;
	ssize_t				buf_len;
	char				*buf;
	struct s_gnl_list	*prev;
	struct s_gnl_list	*next;
}t_list;

void	*ft_memcpy(void *dst, const void *src, size_t n);
t_list	*create_lst(t_list **head, int fd, char **buf, ssize_t buf_len);
int		join_str(t_list **fd_lst, char **save, ssize_t read_len);
int		check_fd(t_list **fd_lst, int fd, char **temp, int read_len);
int		input_str(t_list **fd_lst, int fd, int *is_success);

char	*get_next_line(int fd);
int		create_ret_save(t_list **fd_lst, char **ret, \
	ssize_t ret_len, char **save);
ssize_t	check_line(t_list *fd_lst, ssize_t ret_len);
char	*split_line(t_list **fd_lst, ssize_t *ret_len, int *is_success);
char	*ret_line(t_list **fd_lst, int *is_success);
#endif
