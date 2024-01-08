/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:12:18 by juha              #+#    #+#             */
/*   Updated: 2023/01/16 15:42:39 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_bool	idxing(t_stack_node **top, int stack_size)
{
	t_stack_node	*node;
	int				prev_idx;
	int				i;

	node = *top;
	i = 0;
	prev_idx = -1;
	while (i++ < stack_size)
	{
		if (prev_idx < node->idx)
			prev_idx = node->idx;
		else
			return (FALSE);
		node = node->next;
	}
	return (TRUE);
}

t_bool	is_sorting(t_stack_node *top, int stack_size, t_s_name name)
{
	t_stack_node	*node;
	int				prev_idx;
	int				i;

	node = top;
	i = 0;
	prev_idx = -1;
	if (name == A)
		return (idxing(&top, stack_size));
	else
	{
		while (i++ < stack_size)
		{
			if (prev_idx > node->idx)
				prev_idx = node->idx;
			else
				return (FALSE);
			node = node->next;
		}
	}
	return (TRUE);
}

char	*ft_substr_utils(void)
{
	char	*temp;

	temp = malloc(1);
	if (!temp)
		exit(1);
	*temp = '\0';
	return (temp);
}

char	*ft_substr(char const *s, size_t start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*temp;
	size_t	k;

	if (start > ft_strlen(s))
	{
		temp = ft_substr_utils();
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
