/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 09:20:14 by juha              #+#    #+#             */
/*   Updated: 2023/01/10 02:39:24 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	change_idx(t_stack *stack)
{
	int				cnt;
	t_stack_node	*node;

	node = stack->a_top;
	cnt = stack->total;
	while (cnt--)
	{
		node->origin_num = node->idx;
		node = node->next;
	}
}

int	cnt_split_str(char **argv)
{
	int	i;

	if (!argv)
		return (0);
	i = 0;
	while (argv[i])
		i++;
	return (i);
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
			ret = malloc(sizeof(char *) * (cnt_split_str(temp1) + cnt_split_str(temp2) + 1));
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

int	main(int argc, char **v)
{
	t_stack		stack;
	t_archive	archive;
	char		**argv;

	argv = make_char_pp(argc, v);
	argc = cnt_split_str(argv);
	check_error(argc, argv);
	init_stack(&stack, argc, argv);
	if (is_sorting(stack.a_top, stack.cnt_a, A))
		return (0);
	change_idx(&stack);
	archive.cmd = NULL;
	archive.next = NULL;
	sort_stack(&stack, &archive);
	// system("leaks push_swap");
	return (0);
}
