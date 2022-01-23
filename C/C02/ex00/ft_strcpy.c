/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 17:50:57 by juha              #+#    #+#             */
/*   Updated: 2022/01/17 17:51:06 by juha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = src[i];
	return (dest);
}
/**
int	main(void)
{
	char	a[3];
	int		i;

	i = 0;
	ft_strcpy(a, "aa");
	while (a[i])
	{
		write(1,(a+i), 1);
		i++;
	}
	
}
*/
