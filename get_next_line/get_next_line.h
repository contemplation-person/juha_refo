/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 16:00:51 by juha              #+#    #+#             */
/*   Updated: 2022/04/14 16:44:30 by juha             ###   ########seoul.kr  */
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

char			*get_next_line(int fd);
static size_t	ft_strlen(const char	*s, int *line);
static char		*ft_strjoin(char const *s1, char const *s2);	
static t_list	*ft_lstnew(void *content, int fd);
static void		ft_lstadd(t_list **lst, t_list *new);
char			*ft_substr(char const *s, size_t start, size_t len);

#endif
