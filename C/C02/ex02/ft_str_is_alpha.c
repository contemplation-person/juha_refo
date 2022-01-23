/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 17:51:34 by juha              #+#    #+#             */
/*   Updated: 2022/01/19 19:19:35 by juha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(('a' <= str[i] && str[i] <= 'z')
				|| ('A' <= str[i] && str[i] <= 'Z')))
			return (0);
		i++;
	}
	return (1);
}
/**
#include <stdio.h>
 int main()
 {
    int a = ft_str_is_alpha("aaaaaadf");
    printf("%d", a); 
    return 0;
 }
 */
