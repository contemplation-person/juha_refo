/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:18:44 by juha              #+#    #+#             */
/*   Updated: 2022/11/17 19:21:25 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	is_died(t_info *info)
{
	t_bool	state;

	pthread_mutex_lock(info->mutex + info->total_philo + DH);
	state = info->philo_dead;
	pthread_mutex_unlock(info->mutex + info->total_philo + DH);
	return (state);
}

void	init_time(t_info *info)
{
	int		i;
	t_philo	*philo;

	i = 0;
	while (i < info->total_philo)
	{
		philo = info->philo + i;
		philo->last_eating.tv_sec = info->starting_time.tv_sec;
		philo->last_eating.tv_usec = info->starting_time.tv_usec;
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_info				info;

	if (do_parsing(argc, argv) == FALSE)
		return (EXIT_FAILURE);
	if (init_info(&info, argc, argv) == FALSE)
		return (EXIT_FAILURE);
	if (info.total_philo == 1)
		printf("0 1 died\n");
	if (info.total_philo < 2)
		return (EXIT_SUCCESS);
	if (gettimeofday(&(info.starting_time), NULL) == -1)
		return (EXIT_FAILURE);
	init_time(&info);
	if (create_thread(&info))
		return (EXIT_FAILURE);
	if (destroy_all(&info))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
