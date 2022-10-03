/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:41:33 by maolivei          #+#    #+#             */
/*   Updated: 2022/10/03 15:36:16 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_philos(t_data *data)
{
	size_t	index;

	data->philosophers = malloc(sizeof(t_philo) * data->num_of_philosophers);
	if (!data->philosophers)
		return (free(data->forks), -1);
	index = 0;
	while (index < data->num_of_philosophers)
	{
		data->philosophers[index].data = data;
		data->philosophers[index].done_meals = 0;
		data->philosophers[index].last_meal = 0;
		data->philosophers[index].philo_id = index;
		data->philosophers[index].fork_left = &data->forks[index];
		data->philosophers[index].fork_right = \
			&data->forks[(index + 1) % data->num_of_philosophers];
		++index;
	}
	return (0);
}
