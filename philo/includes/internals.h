/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internals.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 18:49:34 by maolivei          #+#    #+#             */
/*   Updated: 2022/10/03 15:37:46 by maolivei         ###   ########.fr       */
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
typedef struct timeval	t_timeval;
typedef pthread_mutex_t	t_mutex;

typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

struct s_philo
{
	int			philo_id;
	int			done_meals;
	time_t		last_meal;
	t_mutex		*fork_left;
	t_mutex		*fork_right;
	pthread_t	thread_id;
	t_data		*data;
};

struct s_data
{
	size_t	num_of_philosophers;
	int		must_eat;
	time_t	time_to_die;
	time_t	time_to_eat;
	time_t	time_to_sleep;
	time_t	kickstart;
	t_bool	end_of_simulation;
	t_mutex	end_lock;
	t_mutex	print_lock;
	t_mutex	*forks;
	t_philo	*philosophers;
};

#endif /* INTERNALS_H */
