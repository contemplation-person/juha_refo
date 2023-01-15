/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 13:14:58 by juha              #+#    #+#             */
/*   Updated: 2023/01/14 08:38:50 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_bool	is_duplicate(int argc, char **argv)
{
	size_t	argv_len;
	size_t	cmp_len;
	size_t	i;

	while (--argc)
	{
		i = 1;
		while (i < (size_t)argc)
		{
			argv_len = ft_strlen(argv[argc]);
			cmp_len = ft_strlen(argv[i]);
			if (argv_len == cmp_len)
			{
				if (!ft_memcmp(argv[argc], argv[i], cmp_len))
					return (TRUE);
			}
			i++;
		}
	}
	return (FALSE);
}

t_bool	is_int_max(char *argv)
{
	size_t	argv_len;
	long	argv_toi;

	argv_len = ft_strlen(argv);
	if (*argv == '-' || *argv == '+')
		argv_len = ft_strlen(argv + 1);
	if (10 >= argv_len)
	{
		argv_toi = ft_atoi(argv);
		if (-2147483649 < argv_toi && argv_toi < 2147483648)
			return (TRUE);
	}
	return (FALSE);
}

t_bool	is_wrong_input(char *argv)
{
	if (*argv == '-' || *argv == '+')
	{
		argv++;
		if (*argv == '\0')
			write_error_message();
	}
	while (*argv)
	{
		if (!('0' <= *argv && *argv <= '9'))
			return (TRUE);
		argv++;
	}
	return (FALSE);
}

int	write_error_message(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

t_bool	check_error(int argc, char **argv)
{
	static t_bool	state;

	if (argc < 1)
		state = write_error_message();
	if (is_duplicate(argc - 1, argv + 1))
		state = write_error_message();
	argv++;
	while (*argv)
	{
		if (is_wrong_input(*argv))
		{
			state = write_error_message();
		}
		else if (!is_int_max(*argv))
			state = write_error_message();
		argv++;
	}
	if (state)
		exit(1);
	return (0);
}
