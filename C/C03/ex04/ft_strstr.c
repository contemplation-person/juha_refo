/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 19:50:05 by juha              #+#    #+#             */
/*   Updated: 2022/01/20 19:50:06 by juha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_strcmp(char *s1, char *s2, int cnt)
{
	int	i;

	i = 0;
	while ((s1[cnt] == s2[i]) && (s1[cnt] != '\0') && (s2[i] != '\0'))
		i++;
	return (s1[cnt] - s2[i]);
}

char *ft_strstr(char *str, char *to_find)
{
    int i;

    i = -1;
    while(str[++i])
    {
        if(ft_strcmp(&(str[i]), to_find, i) == 0)
            return &(str[i]);
    }
    return (NULL);
}
