/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 20:10:52 by juha              #+#    #+#             */
/*   Updated: 2022/10/13 14:13:53 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <errno.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>
# include "libft/libft.h"
# include "libft/get_next_line.h"

typedef enum s_bool
{
	TRUE = -1,
	FALSE = 0,
}t_bool;

enum e_cmd
{
	READ,
	WRITE,
};

typedef struct s_using_pipe
{
	int	fd[2];
	int	prev_fd;
}t_using_pipe;

typedef struct s_pipe
{
	char	**path;
	int		argc;
	char	**argv;
	char	**envp;
	pid_t	pid_num;
	int		operator_cmd;
	int		status;
}t_pipe;

void	init(t_pipe *p, t_using_pipe *channel, int argc, char **argv);
int		set_collabo(t_pipe *p, char **envp);
char	*parse_file(t_pipe p, char **argv);

void	check_error(int error, char *str);

char	**parse_option(t_pipe p, t_using_pipe channel);
char	*access_file(t_pipe *p, t_using_pipe *channel, int ok);
void	start_child(t_pipe *p, t_using_pipe *channel);
void	other_child(t_pipe *p, t_using_pipe *channel);
void	bottom_child(t_pipe *p, t_using_pipe *channel);
#endif