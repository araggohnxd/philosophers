/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 16:59:46 by maolivei          #+#    #+#             */
/*   Updated: 2022/09/27 20:54:50 by maolivei         ###   ########.fr       */
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

void	*cogito_ergo_sum(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	if (philo->philo_id % 2)
		mssleep(50);
	philo->last_meal = philo->data->kickstart;
	while (!philo->data->has_someone_died)
	{
		philo_eat(philo);
		if (philo->data->must_eat > 0 \
		&& philo->done_meals >= philo->data->must_eat)
			break ;
		philo_sleep(philo);
		philo_think(philo);
	}
	return (NULL);
}
