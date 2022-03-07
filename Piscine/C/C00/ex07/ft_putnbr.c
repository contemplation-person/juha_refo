/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:49:38 by juha              #+#    #+#             */
/*   Updated: 2022/01/26 20:29:46 by juha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned int	ft_change_negative(int nb)
{
	if (nb >= 0)
	{
		return (nb);
	}
	else
	{
		return (-nb);
	}
}

void	ft_print(unsigned int nb)
{
	char	c;

	if (nb / 10)
	{
		ft_print(nb / 10);
		c = nb % 10 + '0';
		write(1, &c, 1);
	}
	else
	{
		c = nb % 10 + '0';
		write(1, &c, 1);
		return ;
	}
}

void	ft_putnbr(int nb)
{
	unsigned int	absolute_nb;

	absolute_nb = ft_change_negative(nb);
	if (nb < 0)
	{
		write(1, "-", 1);
	}
	ft_print (absolute_nb);
}
