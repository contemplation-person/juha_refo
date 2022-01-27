/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 11:28:47 by juha              #+#    #+#             */
/*   Updated: 2022/01/27 18:01:44 by juha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	num;

	num = 1;
	if (nb > 1)
	{
		while (nb)
		{
			num *= nb;
			nb -= 1;
		}
		return (num);
	}
	else if ((nb == 1) || (nb == 0))
		return (1);
	else
		return (0);
}
