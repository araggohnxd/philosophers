/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 16:59:06 by maolivei          #+#    #+#             */
/*   Updated: 2022/09/27 21:19:29 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*cogito_ergo_sum(void *data)
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

void	run_simulation(t_data *data)
{
	size_t		index;

	data->kickstart = get_time_in_ms();
	index = 0;
	while (index < data->num_of_philosophers)
	{
		pthread_create(
			&data->philosophers[index].thread_id,
			NULL,
			cogito_ergo_sum,
			&data->philosophers[index]);
		++index;
	}
	index = 0;
	while (index < data->num_of_philosophers)
		pthread_join(data->philosophers[index++].thread_id, NULL);
}
