/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 11:15:32 by juha              #+#    #+#             */
/*   Updated: 2022/01/26 20:29:34 by juha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	a_2_equal_9(char *a)
{
	if (a[2] != '9')
	{
		a[1] = a[3];
		a[0] = a[2] + 1;
	}
	else
	{
		a[1] = a[3] + 1;
		a[0] = '0';
	}
}

void	divide(int flag)
{
	char	space;
	char	comma;

	comma = ',';
	space = 32;
	if (flag == 1)
	{
		write (1, &space, 1);
	}
	else
	{
		write (1, &comma, 1);
	}
}

void	ft_print(char *a)
{
	write (1, &a[3], 1);
	write (1, &a[2], 1);
	divide(1);
	write (1, &a[1], 1);
	write (1, &a[0], 1);
}

void	cal(char *a)
{
	++a[0];
	if (a[0] > '9')
	{
		a[0] = '0';
		a[1]++;
	}
	if (a[1] > '9')
	{
		a[1] = '0';
		a[2]++;
		a_2_equal_9(a);
	}
	if (a[2] > '9')
	{
		a[2] = '0';
		a[3]++;
		a[0] = a[2] + 1;
		a[1] = a[3];
	}
}

void	ft_print_comb2(void)
{
	char	a[4];

	a[3] = '0';
	a[2] = '0';
	a[1] = '0';
	a[0] = '0';
	while (1)
	{
		cal(a);
		ft_print(a);
		if (a[3] >= '9' && a[2] >= '8' && a[1] >= '9' && a[0] >= '9')
		{
			break ;
		}
		if (a[0] <= '9')
		{
			divide(2);
			divide(1);
		}
	}
}
