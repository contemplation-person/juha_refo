/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conteng <conteng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 16:00:51 by juha              #+#    #+#             */
/*   Updated: 2022/04/22 00:46:24 by conteng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H 

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5000
# endif

# include <stdlib.h>

typedef struct s_str_info
{
	char	*str;
	int		start;
	int		end;
}t_str_info;

typedef struct s_gnl_list
{
	int					fd;
	struct s_str_info	*str_info;
	struct s_gnl_list	*next_fd;
}t_list;

size_t	ft_strlen(const char *s, char c);

#endif
