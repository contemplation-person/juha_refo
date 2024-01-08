/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:29:19 by juha              #+#    #+#             */
/*   Updated: 2022/11/15 18:35:19 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/time.h>
# define INFINITY -2

typedef enum e_bool
{
	FALSE,
	TRUE,
}t_bool;

typedef enum e_philo_state
{
	ERROR = -1,
	READY,
	EATING,
	THINKING,
	SLEEPING,
	PICKING,
	DEATH,
	DONE,
}t_philo_state;

enum e_hand
{
	LEFT,
	RIGHT,
};

enum e_mutex_name
{
	RD,
	DH,
	TM,
};

typedef struct s_philo
{
	int				philo_name;
	int				max_eating_num;
	int				*fork[2];
	pthread_mutex_t	*mutex[2];
	struct timeval	last_eating;
	struct s_info	*info;
	pthread_t		thread_id;
	t_philo_state	state;
}t_philo;

typedef struct s_info
{
	int				total_philo;
	long			time_of_dead;
	long			time_of_eat;
	long			time_of_sleep;
	struct timeval	starting_time;
	t_bool			philo_dead;
	int				*fork;
	t_philo			*philo;
	pthread_mutex_t	*mutex;
}t_info;

int				ft_atoi(const char *str);
size_t			ft_strlen(const char *s);
t_bool			is_error(char *str, char *file);
void			*ft_calloc(size_t count, size_t size);

t_bool			do_parsing(int argc, char **argv);

t_bool			init_info(t_info *info, int argc, char **argv);

long			get_milli_time(struct timeval start, struct timeval now);
long			real_time(t_info *info, t_philo *philo, t_philo_state state);

void			*truman(void *arg);

void			print(t_info *info, t_philo *philo, t_philo_state state);
void			*live(void *arg);
t_bool			create_thread(t_info *info);
t_bool			destroy_all(t_info *info);

t_bool			check_died(t_philo *philo, t_info *info);
t_bool			is_died(t_info *info);
void			eating(t_philo *philo, t_info *info);
void			sleeping(t_philo *philo, t_info *info);
void			thinking(t_philo *philo, t_info *info);
#endif