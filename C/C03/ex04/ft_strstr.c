/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 19:50:05 by juha              #+#    #+#             */
/*   Updated: 2022/01/23 13:58:09 by juha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_strlen(char *str)
{
	int	cnt;

	cnt = 0;
	while (*str)
	{
		cnt++;
		str++;
	}
	return (cnt);
}

int	check_str(char *str, char *to_find, int to_find_len)
{
	int	i;

	i = -1;
	while (++i < to_find_len)
	{
		if (str[i] != to_find[i])
		{
			return (0);
		}
	}
	return (1);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	to_find_len;

	i = -1;
	to_find_len = ft_strlen(to_find);
	if (to_find_len == 0)
		return (str);
	while (str[++i])
	{
		if (str[i] == to_find[0])
		{
			if (check_str((str + i), to_find, to_find_len))
				return (str + i);
		}
	}
	return ('\0');
}
