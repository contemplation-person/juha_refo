/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 16:00:51 by juha              #+#    #+#             */
/*   Updated: 2022/04/24 20:22:00 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H 

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdlib.h>
# include <sys/types.h>

typedef struct s_str_info
{
	char	*buffer;
	ssize_t	end;
}t_str;

typedef struct s_gnl_list
{
	ssize_t				fd;
	struct s_str_info	*str_info;
	struct s_gnl_list	*next_fd_lst;
}t_list;

char	*get_next_line(int fd);
t_list	*chk_lst(t_list **head, ssize_t fd);
char	*ret_line(t_list **head, ssize_t fd, char **str);

ssize_t	ft_strlen(const char *s, ssize_t end);
char	*all_free(t_list	**head, ssize_t fd, char **str);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	new_lst(t_list **head, ssize_t fd, char **str, ssize_t read_len);

#endif
