/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 21:14:02 by maolivei          #+#    #+#             */
/*   Updated: 2022/09/27 21:18:00 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_action(t_philo *philo, const char *action)
{
	const t_time	elapsed_time = get_elapsed_time(philo->data->kickstart);

	printf("%5ld %3d %s\n", elapsed_time, (philo->philo_id + 1), action);
}

void	sweet_dreams(t_philo *philo, t_time sleep_time)
{
	const t_time	started_sleeping = get_time_in_ms();
	t_time			current_time_slept;
	t_time			time_since_last_meal;

	current_time_slept = 0;
	while (current_time_slept < sleep_time)
	{
		if (philo->data->has_someone_died)
			return ;
		usleep(100);
		time_since_last_meal = get_elapsed_time(philo->last_meal);
		if (time_since_last_meal >= philo->data->time_to_die)
			return (philo_die(philo));
		current_time_slept = get_elapsed_time(started_sleeping);
	}
}

void	ft_mutex_unlock(t_mutex *mutex)
{
	pthread_mutex_unlock(&mutex->mutex);
	mutex->is_locked = FALSE;
}

void	ft_mutex_lock(t_mutex *mutex)
{
	pthread_mutex_lock(&mutex->mutex);
	mutex->is_locked = TRUE;
}
