/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:54:27 by juha              #+#    #+#             */
/*   Updated: 2022/11/17 17:21:40 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print(t_info *info, t_philo *philo, t_philo_state state)
{
	struct timeval	now_time;
	char			*str;

	str = NULL;
	if (is_died(info))
		return ;
	pthread_mutex_lock(info->mutex + info->total_philo + TM);
	gettimeofday(&now_time, NULL);
	if (state == PICKING)
		str = "has taken a fork";
	else if (state == EATING)
		str = "is eating";
	else if (state == SLEEPING)
		str = "is sleeping";
	else if (state == THINKING)
		str = "is thinking";
	printf("%ld %d %s\n", get_milli_time(info->starting_time, now_time), \
	philo->philo_name, str);
	pthread_mutex_unlock(info->mutex + info->total_philo + TM);
}

void	*live(void *arg)
{
	t_philo	*philo;
	t_info	*info;

	philo = (t_philo *)arg;
	info = philo->info;
	if (philo->philo_name % 2)
		usleep(150);
	while (1)
	{
		eating(philo, info);
		if (is_died(info) \
			|| (INFINITY < --philo->max_eating_num \
				&& philo->max_eating_num < 1))
			break ;
		sleeping(philo, info);
		thinking(philo, info);
		if (philo->max_eating_num < INFINITY)
			philo->max_eating_num = INFINITY;
	}
	return (NULL);
}

t_bool	create_thread(t_info *info)
{
	static int	i;
	t_philo		*philo;

	while (i < info->total_philo)
	{
		philo = &info->philo[i];
		if (pthread_create(&(philo->thread_id), NULL, live, philo))
			return (FALSE);
		i++;
	}
	i = 0;
	while (i < info->total_philo)
	{
		philo = &info->philo[i];
		if (pthread_join(philo->thread_id, NULL))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

t_bool	destroy_all(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->total_philo + TM + 1)
	{
		if (pthread_mutex_destroy(&info->mutex[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}
