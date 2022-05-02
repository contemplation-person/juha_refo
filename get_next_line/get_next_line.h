/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conteng <conteng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 16:00:51 by juha              #+#    #+#             */
/*   Updated: 2022/05/03 01:00:43 by conteng          ###   ########.fr       */
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

void	*ft_memcpy(void *dst, const void *src, size_t n);
t_list	*create_lst(t_list **head, int fd, char **buf, ssize_t buf_len);
int		join_str(t_list **lst, char **save, ssize_t read_len);

char	*get_next_line(int fd);
int		input_str(t_list **fd_lst, int fd, int *is_success);
char	*ret_line(t_list **fd_lst, int *is_success);
#endif
