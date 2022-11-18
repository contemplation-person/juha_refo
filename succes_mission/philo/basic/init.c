/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:38:02 by juha              #+#    #+#             */
/*   Updated: 2022/11/15 23:22:40 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static t_bool	create_mutex(pthread_mutex_t **mutex, int cnt)
{
	int	i;

	i = 0;
	*mutex = malloc(sizeof(pthread_mutex_t) * cnt);
	while (i < cnt)
	{
		if (pthread_mutex_init((*mutex) + i, NULL))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

static void	give_name(t_info *info)
{
	int		i;
	t_philo	*philo;

	i = 0;
	while (i < info->total_philo)
	{
		philo = info->philo + i;
		philo->philo_name = i + 1;
		philo->info = info;
		i++;
	}
}

static void	set_fork_and_mutex(t_info *info)
{
	static int			i;
	enum e_hand			hd;
	const int			tt = info->total_philo;
	t_philo				*philo;

	while (i < tt)
	{
		philo = info->philo + i;
		hd = philo->philo_name % 2;
		philo->fork[hd] = info->fork + philo->philo_name - 1;
		philo->fork[!hd] = info->fork + (philo->philo_name % tt);
		philo->mutex[hd] = info->mutex + philo->philo_name - 1;
		philo->mutex[!hd] = info->mutex + (philo->philo_name % tt);
		i++;
	}
}

void	set_philo_max_eat(t_info *info, int cnt)
{
	static int	i;
	t_philo		*philo;

	while (i < info->total_philo)
	{
		philo = info->philo + i;
		philo->max_eating_num = cnt;
		i++;
	}
}

t_bool	init_info(t_info *info, int argc, char **argv)
{
	memset(info, 0, sizeof(t_info));
	info->total_philo = ft_atoi(argv[1]);
	info->fork = ft_calloc(info->total_philo, sizeof(int));
	info->philo = ft_calloc(info->total_philo, sizeof(t_philo));
	if (!info->fork || !info->philo || \
		!create_mutex(&(info->mutex), info->total_philo + TM + 1))
		return (FALSE);
	give_name(info);
	set_fork_and_mutex(info);
	info->time_of_dead = ft_atoi(argv[2]);
	info->time_of_eat = ft_atoi(argv[3]);
	info->time_of_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		set_philo_max_eat(info, ft_atoi(argv[5]));
	else
		set_philo_max_eat(info, INFINITY);
	return (TRUE);
}
