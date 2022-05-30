/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 03:00:15 by juha	           #+#    #+#             */
/*   Updated: 2022/05/25 16:52:16 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_success	chk_persent(const char *form)
{
	int	i;

	i = 0;
	while (form[i])
	{
		if (form[i] == '%')
			return (SUCCESS);
		i++;
	}
	return (ERROR);
}
