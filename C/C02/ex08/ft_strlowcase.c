/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 12:07:39 by juha              #+#    #+#             */
/*   Updated: 2022/01/19 12:08:44 by juha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ('A' <= str[i] && str[i] <= 'Z')
			str[i] = str[i] + 32;
		i++;
	}
	return (str);
}
/**
#include <stdio.h>
int main ()
{
    char str[5] = {'a', '/', 'E', '1','\0'};
    printf("%s", ft_strlowcase(str));

    return 0;
}
*/
