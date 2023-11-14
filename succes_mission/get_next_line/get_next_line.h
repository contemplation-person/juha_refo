/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 16:00:51 by juha              #+#    #+#             */
/*   Updated: 2022/05/12 18:44:46 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H 

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <limits.h>
# include <sys/types.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 1024


typedef struct s_gnl
{
	int 				fd;
	char				*rb;
	int					rb_capacity;
}t_gnl;

char		*get_next_line(int fd);

#endif
