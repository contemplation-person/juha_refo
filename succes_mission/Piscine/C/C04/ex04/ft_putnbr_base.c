/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 09:56:26 by juha              #+#    #+#             */
/*   Updated: 2022/01/27 17:25:15 by juha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	nonavailable_base(char *base)
{
	int	i;
	int	j;

	i = -1;
	while (base[++i])
	{
		if ((9 <= base[i] && base[i] <= 13) || 32 == base[i])
			return (1);
		if ((base[i] == '+') || (base[i] == '-'))
			return (1);
		j = i;
		while (base[++j])
		{
			if (base[i] == base[j])
				return (1);
		}
	}
	return (0);
}

int	cnt_numsys(char *base)
{
	int	i;

	i = 0;
	while (base[i])
		i++;
	return (i);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int					numsys;
	unsigned int		unsign;

	numsys = cnt_numsys(base);
	if (nonavailable_base(base) && numsys <= 1)
		return ;
	if (nbr < 0 )
	{
		write(1, "-", 1);
		unsign = -nbr;
	}
	else
		unsign = nbr;
	if (unsign == 0)
		return ;
	ft_putnbr_base(unsign / numsys, base);
	write(1, (base + (unsign % numsys)), 1);
}
