/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 22:31:01 by juha              #+#    #+#             */
/*   Updated: 2022/10/11 18:58:22 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	here_doc(t_pipe *p, t_using_pipe *channel)
{
	char	*str;
	int		fd;
	char	*gnl;

	close(channel->fd[READ]);
	close(channel->prev_fd);
	str = "";
	while (1)
	{
		gnl = get_next_line(STDIN_FILENO);
		if (!ft_strncmp(gnl, p->argv[2], ft_strlen(p->argv[2])) && \
			ft_strlen(gnl) - 1 == ft_strlen(p->argv[2]))
			break ;
		str = ft_strjoin(str, gnl);
	}
	ft_putstr_fd(str, channel->fd[WRITE]);
	close(channel->fd[WRITE]);
}
