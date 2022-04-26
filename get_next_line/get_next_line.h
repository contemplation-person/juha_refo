/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 16:00:51 by juha              #+#    #+#             */
/*   Updated: 2022/04/26 18:07:00 by juha             ###   ########seoul.kr  */
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

#endif
