/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internals.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 18:49:34 by maolivei          #+#    #+#             */
/*   Updated: 2022/09/27 21:02:47 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNALS_H
# define INTERNALS_H

/* External libraries */
# include <pthread.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_data	t_data;
typedef struct s_philo	t_philo;
typedef struct s_mutex	t_mutex;
typedef struct timeval	t_timeval;
typedef long			t_time;

typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

struct s_mutex
{
	pthread_mutex_t	mutex;
	t_bool			is_locked;
};

struct s_philo
{
	int			philo_id;
	int			done_meals;
	t_time		last_meal;
	t_mutex		*fork_left;
	t_mutex		*fork_right;
	pthread_t	thread_id;
	t_data		*data;
};

struct s_data
{
	size_t	num_of_philosophers;
	int		must_eat;
	t_time	time_to_die;
	t_time	time_to_eat;
	t_time	time_to_sleep;
	t_time	kickstart;
	t_bool	has_someone_died;
	t_mutex	*forks;
	t_philo	*philosophers;
};

#endif /* INTERNALS_H */
