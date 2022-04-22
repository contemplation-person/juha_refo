/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conteng <conteng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 16:00:51 by juha              #+#    #+#             */
/*   Updated: 2022/04/23 01:47:06 by conteng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H 

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5000
# endif

# include <stdlib.h>
# include <sys/types.h>

typedef struct s_str_info
{
	char	*buffer;
	ssize_t	start;
	ssize_t	end;
	ssize_t	check_null;
}t_str;

typedef struct s_gnl_list
{
	ssize_t				fd;
	struct s_str_info	*str_info;
	struct s_gnl_list	*next_fd_lst;
}t_list;

char	*get_next_line(int fd);
t_list	*chk_lst(t_list *head, ssize_t fd);
char	*ret_line(t_list **head, ssize_t fd, char **str);

ssize_t	ft_strlen(const char *s, ssize_t start, ssize_t end);
char	*all_free(t_list	**head, ssize_t fd, char **str);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	new_lst(t_list **head, ssize_t fd, char **str, ssize_t read_len);


#endif
