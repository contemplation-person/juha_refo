/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 19:50:05 by juha              #+#    #+#             */
/*   Updated: 2022/01/22 15:51:32 by juha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (s1[0] == '\0' && s1[0] == '\0')
		return (0);
	while ((s1[i] == s2[i]) && (s1[i] != '\0') && (s2[i] != '\0'))
		i++;
	return (s1[i - 1] - s2[i - 1]);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;

	i = -1;
	if (str[0] == '\0')
		return (NULL);
    if(!str[i + 1] && !to_find[i + 1])
        return (str);
	while (str[++i])
	{
		if (ft_strcmp(&(str[i]), to_find) == 0)
			return (&(str[i]));
	}
	return (NULL);
}
