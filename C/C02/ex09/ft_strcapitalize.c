/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 12:08:58 by juha              #+#    #+#             */
/*   Updated: 2022/01/26 21:07:17 by juha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	is_first;

	is_first = 1;
	i = -1;
	while (str[++i])
	{
		if (is_first == 1 && 'a' <= str[i] && str[i] <= 'z')
		{
			str[i] -= 32;
			is_first = 0;
		}
		else if (is_first == 0 && 'A' <= str[i] && str[i] <= 'Z')
			str[i] += 32;
		else if (is_first == 1 && '0' <= str[i] && str[i] <= '9')
			is_first = 0;
		else if ((str[i] < '0') || ('9' < str[i] && str[i] < 'A')
			|| ('Z' < str[i] && str[i] < 'a') || 'z' < str[i])
			is_first = 1;
		else
			is_first = 0;
	}
	return (str);
}
