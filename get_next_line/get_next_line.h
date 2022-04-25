/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conteng <conteng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 16:00:51 by juha              #+#    #+#             */
/*   Updated: 2022/04/25 15:25:44 by conteng          ###   ########.fr       */
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
	ssize_t				buffer_len;
	char				*buffer;
	struct s_gnl_list	*next;
}t_list;

char	*get_next_line(int fd);
t_list	*chk_lst(t_list **head, ssize_t fd);
char	*ret_line(t_list **head, ssize_t fd, char **str);

ssize_t	ft_strlen(const char *s, ssize_t end);
char	*all_free(t_list	**head, ssize_t fd, char **str);
void	*ft_memcpy(void *dst, const void *src, size_t n);
int		new_lst(t_list **head, ssize_t fd, char **str, ssize_t read_len);

#endif
