/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 20:44:05 by seongyle          #+#    #+#             */
/*   Updated: 2022/04/21 16:54:10 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5000
# endif

typedef struct s_list
{
	int				fd;
	int				line_len;
	char			*line;
	struct s_list	*next;
	struct s_list	*prev;
}t_list;

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s, char c);
t_list	*creat_node(int fd, char *line);

#endif
