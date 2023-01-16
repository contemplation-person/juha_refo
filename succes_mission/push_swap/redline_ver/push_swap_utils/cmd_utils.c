/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:38:59 by juha              #+#    #+#             */
/*   Updated: 2023/01/16 15:51:19 by juha             ###   ########seoul.kr  */
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

char	**make_char_pp_utils(char ***ret, char ***temp1, char ***temp2)
{
	int	i;

	i = 0;
	*ret = malloc(sizeof(char *) * (cnt_split_str(*temp1) + \
	cnt_split_str(*temp2) + 1));
	if (!(*ret))
		exit(1);
	while (i < cnt_split_str(*temp1) + cnt_split_str(*temp2))
	{
		if (i < cnt_split_str(*temp1))
			(*ret)[i] = (*temp1)[i];
		else
			(*ret)[i] = (*temp2)[i - cnt_split_str(*temp1)];
		i++;
	}
	free(*temp1);
	free(*temp2);
	(*ret)[i] = NULL;

	return (*ret);
}

char	**make_char_pp(int argc, char **argv)
{
	char	**ret;
	char	**temp1;
	char	**temp2;
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
			ret = make_char_pp_utils(&ret, &temp1, &temp2);
	}
	return (ret);
}
