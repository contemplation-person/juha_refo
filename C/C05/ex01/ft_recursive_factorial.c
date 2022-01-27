/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 11:29:01 by juha              #+#    #+#             */
/*   Updated: 2022/01/27 11:31:24 by juha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	int	num;

	num = 0;
	if (nb > 1)
	{
		num = nb;
		return (num *= ft_recursive_factorial(nb - 1));
	}
	else if ((nb == 1) || (nb == 0))
		return (1);
	else
		return (0);
}
