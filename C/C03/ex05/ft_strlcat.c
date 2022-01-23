/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 13:58:26 by juha              #+#    #+#             */
/*   Updated: 2022/01/23 14:01:27 by juha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dest_len;
	unsigned int	src_len;
	unsigned int	i;

	i = 0;
	dest_len = check_len(dest);
	src_len = check_len(src);
	if (size <= dest_len)
		return (size + src_len);
	else
	{
		while (dest[i])
			i++;
		while (i + 1 < size || src[i] != '\0')
		{
			dest[i] = *src;
			i++;
			src++;
		}
		dest[i] = '\0';
		return (dest_len + src_len);
	}
}
