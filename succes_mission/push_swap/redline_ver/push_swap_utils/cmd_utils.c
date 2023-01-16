/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:38:59 by juha              #+#    #+#             */
/*   Updated: 2023/01/16 11:13:54 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack_node	*pop(t_stack_node **top, int *cnt_stack)
{
	t_stack_node	*ret;

	ret = (*top);
	if (*cnt_stack == 1)
		(*top) = NULL;
	else if (*cnt_stack > 1)
	{
		(*top) = (*top)->next;
		(*top)->prev = ret->prev;
		ret->prev->next = (*top);
		ret->next = ret;
		ret->prev = ret;
	}
	else
		return (NULL);
	(*cnt_stack)--;
	return (ret);
}

t_bool	push(t_stack_node **target, t_stack_node *src, int *size)
{
	if (!src)
		return (FALSE);
	if (*size > 0)
	{
		(*target)->prev->next = src;
		src->next = (*target);
		src->prev = (*target)->prev;
		(*target)->prev = src;
		(*target) = src;
	}
	else
		(*target) = src;
	(*size)++;
	return (TRUE);
}

char	*ft_substr(char const *s, size_t start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*temp;
	size_t	k;

	if (start > ft_strlen(s))
	{
		temp = malloc(1);
		if (!temp)
			exit(1);
		*temp = '\0';
		return (temp);
	}
	k = 0;
	while (s[start + k])
		k++;
	if (len > k)
		len = k;
	temp = (char *)malloc(len + 1);
	if (!temp)
		return (0);
	i = start;
	j = 0;
	while (j < len)
		temp[j++] = (char)s[i++];
	temp[j] = '\0';
	return (temp);
}

char	**make_char_pp(int argc, char **argv)
{
	char	**ret;
	char	**temp1;
	char	**temp2;
	int		i;
	int		j;

	ret = NULL;
	j = 1;
	while (j < argc)
	{
		temp2 = ft_split(argv[j++], ' ');
		if (!temp2)
			exit(1);
		temp1 = ret;
		if (ret == NULL)
			ret = temp2;
		else
		{
			i = 0;
			ret = malloc(sizeof(char *) * (cnt_split_str(temp1) + \
			cnt_split_str(temp2) + 1));
			if (!ret)
				exit(1);
			while (i < cnt_split_str(temp1) + cnt_split_str(temp2))
			{
				if (i < cnt_split_str(temp1))
					ret[i] = temp1[i];
				else
					ret[i] = temp2[i - cnt_split_str(temp1)];
				i++;
			}
			free(temp1);
			free(temp2);
			ret[i] = NULL;
		}
	}
	return (ret);
}
