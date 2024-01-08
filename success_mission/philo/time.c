/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 21:55:10 by juha              #+#    #+#             */
/*   Updated: 2022/11/15 21:56:07 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_milli_time(struct timeval start, struct timeval now)
{
	return (now.tv_sec * 1000 + now.tv_usec / 1000 \
			- start.tv_sec * 1000 - start.tv_usec / 1000);
}

long	real_time(t_info *info, t_philo *philo, t_philo_state state)
{
	struct timeval	now;
	long			operation_time;

	gettimeofday(&now, NULL);
	if (state == EATING)
	{
		operation_time = get_milli_time(philo->last_eating, now) + \
		info->time_of_eat;
	}
	else
	{
		operation_time = get_milli_time(philo->last_eating, now) + \
		info->time_of_sleep;
	}
	while (get_milli_time(philo->last_eating, now) < operation_time)
	{
		if (check_died(philo, info) == FALSE)
			return (0);
		usleep(250);
		gettimeofday(&now, NULL);
	}
	return (operation_time);
}
