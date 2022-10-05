/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:41:33 by maolivei          #+#    #+#             */
/*   Updated: 2022/10/04 21:41:03 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	init_philos(t_data *data)
{
	size_t	index;

	data->philosophers = malloc(sizeof(t_philo) * data->num_of_philosophers);
	if (!data->philosophers)
		return (-1);
	index = 0;
	while (index < data->num_of_philosophers)
	{
		data->philosophers[index].philo_id = index;
		data->philosophers[index].data = data;
		data->philosophers[index].done_meals = 0;
		data->philosophers[index].process_id = 0;
		++index;
	}
	return (0);
}
