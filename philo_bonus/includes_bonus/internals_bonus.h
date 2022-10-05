/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internals_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 18:49:34 by maolivei          #+#    #+#             */
/*   Updated: 2022/10/05 13:37:28 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNALS_BONUS_H
# define INTERNALS_BONUS_H

/* External libraries */
# include <pthread.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <semaphore.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/time.h>

# define SEM_FORKS "/forks"
# define SEM_END "/end_lock"
# define SEM_PRINT "/print_lock"
# define SEM_OVER "/end_of_simulation"

typedef struct s_data	t_data;
typedef struct s_philo	t_philo;
typedef struct timeval	t_timeval;

typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

struct s_philo
{
	int		philo_id;
	int		done_meals;
	time_t	last_meal;
	pid_t	process_id;
	t_data	*data;
};

struct s_data
{
	size_t	num_of_philosophers;
	int		must_eat;
	time_t	time_to_die;
	time_t	time_to_eat;
	time_t	time_to_sleep;
	time_t	kickstart;
	sem_t	*forks;
	sem_t	*print_lock;
	sem_t	*end_lock;
	sem_t	*end_of_simulation;
	t_philo	*philosophers;
};

#endif /* INTERNALS_BONUS_H */
