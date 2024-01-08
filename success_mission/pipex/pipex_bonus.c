/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 20:09:00 by juha              #+#    #+#             */
/*   Updated: 2022/10/11 18:17:17 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	check_error(int error, char *str)
{
	if (error == -1)
	{
		perror(str);
		exit(1);
	}
}

static void	pipe_n_fork(t_pipe *p, t_using_pipe *channel)
{
	if (p->pid_num > 0 && p ->operator_cmd != p->argc - 4)
		check_error(pipe(channel->fd), "pipex.c - 34");
	p->pid_num = fork();
	if (p->pid_num > 0)
	{
		if (channel->prev_fd != -1)
			close(channel->prev_fd);
		channel->prev_fd = channel->fd[READ];
		close(channel->fd[WRITE]);
	}
}

void	end_parent(t_pipe *p, t_using_pipe channel)
{
	int	i;
	int	status;

	i = p->operator_cmd;
	if (p->pid_num > 0)
	{
		close(channel.prev_fd);
		while (i--)
		{
			if (p->pid_num == waitpid(-1, &status, 0))
				p->status = status;
		}
	}
}

void	do_child(t_pipe *p, t_using_pipe *channel)
{
	if (p->pid_num == 0)
	{
		if (p->operator_cmd == 0 && !ft_strncmp(p->argv[1], "here_doc", 9))
			here_doc(p, channel);
		else if (p->operator_cmd == 0)
			start_child(p, channel);
		else if (p->operator_cmd == p->argc - 4)
			bottom_child(p, channel);
		else
			other_child(p, channel);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_pipe			p;
	t_using_pipe	channel;

	if (argc < 5)
		check_error(-1, "ARG");
	init(&p, &channel, argc, argv);
	set_collabo(&p, envp);
	while (p.operator_cmd < argc - 3)
	{
		pipe_n_fork(&p, &channel);
		if (p.pid_num == 0)
			break ;
		p.operator_cmd++;
	}
	do_child(&p, &channel);
	end_parent(&p, channel);
	return ((p.status >> 8) & 0xFF);
}
