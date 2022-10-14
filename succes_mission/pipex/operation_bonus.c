/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 22:31:01 by juha              #+#    #+#             */
/*   Updated: 2022/10/14 13:31:55 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*access_file(t_pipe *p, t_using_pipe *channel, int ok)
{
	char	*ret;
	char	**path;
	char	**file;

	file = ft_split(p->argv[p->operator_cmd + 2], ' ');
	file[0] = ft_strjoin("/", file[0]);
	path = p->path;
	while (*path)
	{
		ret = ft_strjoin(*path, file[0]);
		if (!access(ret, ok))
			return (ret);
		path++;
	}
	if (!access(&file[0][1], ok))
		return (ft_strdup(&file[0][1]));
	p->status = 127;
	return (NULL);
}

char	**parse_option(t_pipe p, t_using_pipe channel)
{
	char	**ret;

	ret = ft_split(p.argv[p.operator_cmd + 2], ' ');
	ret[0] = access_file(&p, &channel, F_OK);
	return (ret);
}

void	start_child(t_pipe *p, t_using_pipe *channel)
{
	int		fd;
	char	*file;

	close(channel->fd[READ]);
	fd = open(p->argv[1], O_RDONLY);
	dup2(fd, STDIN_FILENO);
	close(fd);
	dup2(channel->fd[WRITE], STDOUT_FILENO);
	close(channel->fd[WRITE]);
	file = access_file(p, channel, F_OK);
	if (!file)
	{
		perror("command not found");
		exit(p->status);
	}
	check_error(execve(file, parse_option(*p, *channel), p->envp), \
	"operate.c - 48");
}

void	other_child(t_pipe *p, t_using_pipe *channel)
{
	char	*file;

	close(channel->fd[READ]);
	dup2(channel->prev_fd, STDIN_FILENO);
	close(channel->prev_fd);
	dup2(channel->fd[WRITE], STDOUT_FILENO);
	close(channel->fd[WRITE]);
	file = access_file(p, channel, F_OK);
	if (!file)
		check_error(-1, "faild access-2");
	check_error(execve(file, parse_option(*p, *channel), p->envp), \
	"operate.c - 39");
}

void	bottom_child(t_pipe *p, t_using_pipe *channel)
{
	int		fd;
	char	*file;

	check_error(dup2(channel->prev_fd, STDIN_FILENO), "operate.c - 81");
	close(channel->prev_fd);
	if (ft_strncmp(p->argv[1], "here_doc", 9))
		fd = open(p->argv[p->argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	else
		fd = open(p->argv[p->argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0777);
	check_error(dup2(fd, STDOUT_FILENO), "operate.c - 87");
	close(fd);
	file = access_file(p, channel, F_OK);
	if (!file)
	{
		perror("command not found");
		exit(p->status);
	}
	check_error(execve(file, parse_option(*p, *channel), p->envp), \
	"operate.c - 39");
}
