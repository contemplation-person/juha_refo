/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 22:10:47 by juha              #+#    #+#             */
/*   Updated: 2022/10/07 21:22:17 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init(t_pipe *p, t_using_pipe *channel, int argc, char **argv)
{
	ft_bzero(channel, sizeof(t_using_pipe));
	ft_bzero(p, sizeof(t_pipe));
	p->argc = argc;
	p->argv = argv;
	channel->prev_fd = -1;
	p->pid_num = 1;
}

int	set_collabo(t_pipe *p, char **envp)
{
	int	i;

	i = 0;
	p->envp = envp;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "PATH=", 5))
			p->path = ft_split(&((envp[i])[5]), ':');
		i++;
	}
	if (p->path == NULL)
	{
		perror("parsing.c - set pipe");
		exit(1);
	}
	return (1);
}

char	*parse_file(t_pipe p, char **argv)
{
	int		i;
	char	str[2];

	i = 0;
	str[0] = '/';
	str[1] = '\0';
	while (argv[p.operator_cmd + 2][i])
	{
		if ((8 < argv[p.operator_cmd + 2][i] \
			&& argv[p.operator_cmd + 2][i] < 14) \
			|| argv[p.operator_cmd + 2][i] == 32)
			break ;
		i++;
	}
	return (ft_substr(ft_strjoin(str, argv[p.operator_cmd + 2]), 0, i));
}
