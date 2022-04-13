/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 16:00:51 by juha              #+#    #+#             */
/*   Updated: 2022/04/13 19:53:29 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H 

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5000
# endif

# include <stdlib.h>

typedef struct s_gnl_list
{
	size_t				fd;
	void				*content;
	struct s_gnl_list	*next;
}t_list;

char	*get_next_line(int fd);
size_t	ft_strlen(const char	*s);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstadd(t_list **lst, t_list *new);
t_list	*ft_lstnew(void *content, int fd);

#endif
