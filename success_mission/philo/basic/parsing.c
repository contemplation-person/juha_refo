/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:45:31 by juha              #+#    #+#             */
/*   Updated: 2022/11/10 18:14:09 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static t_bool	is_digit(char *str)
{
	while (*str)
	{
		if (!('0' <= *str && *str <= '9'))
			return (FALSE);
		str++;
	}
	return (TRUE);
}

t_bool	do_parsing(int argc, char **argv)
{
	int	i;
	int	check_argv;

	i = 1;
	if (!(4 < argc && argc < 7) && is_error("check_argc : ", __FILE__))
		return (FALSE);
	while (i < argc)
	{
		if (!is_digit(argv[i]) && is_error("check_argv : ", __FILE__))
			return (FALSE);
		check_argv = ft_atoi(argv[i]);
		if (check_argv < 0 && is_error("check_argv : ", __FILE__))
			return (FALSE);
		i++;
	}
	return (TRUE);
}
