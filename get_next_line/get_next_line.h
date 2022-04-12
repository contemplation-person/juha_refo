/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conteng <conteng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 16:00:51 by juha              #+#    #+#             */
/*   Updated: 2022/04/12 14:01:13 by conteng          ###   ########.fr       */
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
