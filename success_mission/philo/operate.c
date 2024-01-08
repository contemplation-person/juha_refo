/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:17:31 by juha              #+#    #+#             */
/*   Updated: 2022/11/17 19:23:27 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	check_died(t_philo *philo, t_info *info)
{
	struct timeval	now;
	struct timeval	start;

	start = info->starting_time;
	gettimeofday(&now, NULL);
	pthread_mutex_lock(info->mutex + info->total_philo + DH);
	if (info->philo_dead)
	{
		pthread_mutex_unlock(info->mutex + info->total_philo + DH);
		return (FALSE);
	}
	else if (get_milli_time(start, now) > \
	get_milli_time(start, philo->last_eating) + info->time_of_dead)
	{		
		info->philo_dead = TRUE;
		printf("%ld %d died\n", get_milli_time(start, now), \
		philo->philo_name);
		pthread_mutex_unlock(info->mutex + info->total_philo + DH);
		return (FALSE);
	}
	pthread_mutex_unlock(info->mutex + info->total_philo + DH);
	return (TRUE);
}

void	pick_fork(t_philo *philo, t_info *info)
{
	enum e_hand	hand;

	hand = RIGHT;
	pthread_mutex_lock(philo->mutex[hand]);
	if (*(philo->fork[hand]) == 0)
		*(philo->fork[hand]) = philo->philo_name;
	pthread_mutex_unlock(philo->mutex[hand]);
	pthread_mutex_lock(philo->mutex[!hand]);
	if (*(philo->fork[!hand]) == 0)
		*(philo->fork[!hand]) = philo->philo_name;
	pthread_mutex_unlock(philo->mutex[!hand]);
}

void	eating(t_philo *philo, t_info *info)
{
	enum e_hand	hand;

	hand = RIGHT;
	while (1)
	{
		pick_fork(philo, info);
		if (*(philo->fork[hand]) == philo->philo_name && \
			*(philo->fork[!hand]) == philo->philo_name)
			break ;
		if (!check_died(philo, info))
			return ;
	}
	print(info, philo, PICKING);
	print(info, philo, PICKING);
	print(info, philo, EATING);
	if (is_died(info) || check_died(philo, info) == FALSE)
		return ;
	gettimeofday(&(philo->last_eating), NULL);
	real_time(info, philo, EATING);
	pthread_mutex_lock(philo->mutex[hand]);
	pthread_mutex_lock(philo->mutex[!hand]);
	*(philo->fork[hand]) = 0;
	*(philo->fork[!hand]) = 0;
	pthread_mutex_unlock(philo->mutex[!hand]);
	pthread_mutex_unlock(philo->mutex[hand]);
}

void	sleeping(t_philo *philo, t_info *info)
{
	if (is_died(info))
		return ;
	print(info, philo, SLEEPING);
	if (!real_time(info, philo, SLEEPING))
		return ;
}

void	thinking(t_philo *philo, t_info *info)
{
	if (is_died(info))
		return ;
	print(info, philo, THINKING);
}
