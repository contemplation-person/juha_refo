/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 11:29:07 by juha              #+#    #+#             */
/*   Updated: 2022/01/27 11:30:34 by juha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	if (0 <= nb)
	{
		if (power == 0)
			return (1);
		else if (nb > 0 && power > 0)
			return (nb * ft_recursive_power(nb, power - 1));
		else
			return (0);
	}
	else
		return (0);
}
