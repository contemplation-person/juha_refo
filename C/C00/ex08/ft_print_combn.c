/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 18:06:04 by juha              #+#    #+#             */
/*   Updated: 2022/01/26 20:29:58 by juha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*init(char *str, int n)
{
	int	i;

	i = -1;
	while (i++ != n + 1)
		str[i] = '\0';
	while (0 != --i)
		str[i - 1] = '0' + i - 1;
	return (str);
}

int	check_not_max(char *str, int n)
{
	int	i;
	int	chk;

	chk = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '9')
			chk++;
		i++;
	}
	if (chk == n - 1)
		return (0);
	else
		return (1);
}

void	make_comb(char *str, int n)
{
	int	i;
	int	j;

	j = 0;
	i = n - 1;
	*(str + i) += 1;
	while (j++ < n)
	{
		if (*(str + --i) == '9' + 1)
		{
			*(str + i) = *(str + i - 1) + 1;
			*(str + i - 1) += 1;
		}
	}
}

void	ft_print_combn(int n)
{
	char	str[11];

	if (0 < n || n < 10)
	{
		init(str, n);
		while (1)
		{
			write(1, str, n);
			if (check_not_max(str, n))
			{
				write(1, ", ", 2);
				make_comb(str, n);
			}
			else
				return ;
		}
	}
}
