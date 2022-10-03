/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 16:59:06 by maolivei          #+#    #+#             */
/*   Updated: 2022/10/03 16:15:44 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*cogito_ergo_sum(void *content)
{
	t_philo	*philo;

	philo = (t_philo *)content;
	// if (philo->philo_id % 2)
	// 	usleep(100);
	while (philo_eat(philo) && philo_sleep(philo) && philo_think(philo))
		continue ;
	return (NULL);
}

void	run_simulation(t_data *data)
{
	size_t	index;

	data->kickstart = get_time_in_ms();
	index = 0;
	while (index < data->num_of_philosophers)
	{
		data->philosophers[index].last_meal = data->kickstart;
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
