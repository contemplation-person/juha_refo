/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 12:22:43 by juha              #+#    #+#             */
/*   Updated: 2022/01/26 21:07:08 by juha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	init(char *al)
{
	int	i;

	i = -1;
	while (++i < 17)
	{
		if (i < 10)
			al[i] = '0' + i;
		else
			al[i] = 'a' + (i % 10);
	}
	al[17] = '\0';
}

void	ft_putstr_non_printable(char *str)
{
	int				i;
	char			al[17];
	unsigned char	un_c;

	i = 0;
	init(al);
	while (str[i])
	{
		un_c = str[i];
		if (!(32 <= un_c && un_c <= 126))
		{
			write (1, "\\", 1);
			write (1, &al[un_c / 16], 1);
			write (1, &al[un_c % 16], 1);
		}
		else
			write (1, &un_c, 1);
		i++;
	}
}
