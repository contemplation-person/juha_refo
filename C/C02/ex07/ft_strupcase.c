/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 12:06:34 by juha              #+#    #+#             */
/*   Updated: 2022/01/19 12:07:29 by juha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ('a' <= str[i] && str[i] <= 'z')
			str[i] = str[i] - 32;
		i++;
	}
	return (str);
}
/**
#include <stdio.h>
int main ()
{
    char str[5] = {'a', '/', 'E', '1','\0'};
    printf("%s", ft_strupcase(str));

    return 0;
}
*/
