/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 11:29:14 by juha              #+#    #+#             */
/*   Updated: 2022/01/27 18:01:51 by juha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	long int	i;

	i = 0;
	if (nb < 0)
		return (0);
	while (i <= (long)nb / 2)
	{
		if (i * i == nb)
			return (i);
		i++;
	}
	return (0);
}

int	ft_is_prime(int nb)
{
	long int	i;

	if (1 < nb)
	{
		i = 1;
		while (i < ft_sqrt(nb))
		{
			i++;
			if (nb % i == 0)
				return (0);
		}
		return (1);
	}
	return (0);
}

int	ft_find_next_prime(int nb)
{
	int	i;

	i = nb;
	if (1 > i)
		return (0);
	while (1)
	{
		if (ft_is_prime(i) == 1)
			return (i);
		i++;
	}
}
