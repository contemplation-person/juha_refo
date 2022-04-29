/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 16:00:51 by juha              #+#    #+#             */
/*   Updated: 2022/04/28 20:39:30 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H 

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
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

t_list	*check_fd(t_list **head, int fd);
void	free_lst(t_list **target_lst);
t_list	*create_lst(t_list **head, int fd);
ssize_t	ft_strlen(const char *s, ssize_t end);
void	*ft_memcpy(void *dst, const void *src, size_t n);

char	*ret_line(t_list **fd_lst);
char	*get_next_line(int fd);
int		make_ret_and_save(char **ret, char **save, \
t_list **fd_lst, ssize_t ret_len);
t_list	*input_buf(t_list **fd_lst, int fd, char **read_str, ssize_t read_len);

#endif
