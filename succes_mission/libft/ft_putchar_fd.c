/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conteng <conteng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 00:53:09 by conteng           #+#    #+#             */
/*   Updated: 2022/04/02 12:32:51 by conteng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0) return ;
	int len = write(fd, &c, 1);
	if (len < 0) return ;
	while (len != 1)
		len = write(fd, &c, 1);
}
