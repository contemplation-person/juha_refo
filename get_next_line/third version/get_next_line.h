/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 16:00:51 by juha              #+#    #+#             */
/*   Updated: 2022/04/20 16:39:39 by juha             ###   ########seoul.kr  */
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
	int					fd;
	void				*content;
	struct s_gnl_list	*next;
}t_list;

char	*get_next_line(int fd);
t_list	*ft_lstnew(void *content, int fd);
int		ft_lstclear(t_list **lst, int fd);
size_t	ft_strlen(const char *s, char c);

void	ft_lstadd_back(t_list **lst, t_list *new);

#endif
