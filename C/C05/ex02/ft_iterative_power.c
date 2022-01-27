/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 11:29:05 by juha              #+#    #+#             */
/*   Updated: 2022/01/27 18:01:46 by juha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	while_num(int nb, int power)
{
	int	i;

	i = 1;
	while (0 < power)
	{
		i *= nb;
		power--;
	}
	return (i);
}

int	ft_iterative_power(int nb, int power)
{
	if (power == 0)
		return (1);
	else if (0 > power)
		return (0);
	else if (0 <= nb)
		return (while_num(nb, power));
	else
		return (while_num(nb, power));
}
