/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 11:15:32 by juha              #+#    #+#             */
/*   Updated: 2022/01/26 20:29:19 by juha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print(char *a)
{
	write (1, &a[2], 1);
	write (1, &a[1], 1);
	write (1, &a[0], 1);
}

void	divide_num(void)
{
	char	comma;
	char	space;

	comma = ',';
	space = 32;
	write (1, &comma, 1);
	write (1, &space, 1);
}

void	cal(char *a)
{
	a[0]++;
	if (a[0] > '9')
	{
		a[1] += 1;
		a[0] = a[1] + 1;
	}
	if (a[1] > '8')
	{
		a[2] += 1;
		a[1] = a[2] + 1;
		a[0] = a[1] + 1;
	}
}

void	ft_print_comb(void)
{
	char	a[3];

	a[2] = '0';
	a[1] = '1';
	a[0] = '2';
	while (1)
	{
		ft_print(a);
		cal(a);
		if (a[2] < '8')
		{
			divide_num();
		}
		if (a[2] == '8')
		{
			break ;
		}
	}
}
