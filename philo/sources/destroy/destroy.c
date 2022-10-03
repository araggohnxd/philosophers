/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 12:18:16 by maolivei          #+#    #+#             */
/*   Updated: 2022/10/03 15:38:38 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_data(t_data *data)
{
	size_t	index;

	index = 0;
	while (index < data->num_of_philosophers)
		pthread_mutex_destroy(&(data->forks[index++]));
	pthread_mutex_destroy(&data->end_lock);
	pthread_mutex_destroy(&data->print_lock);
	free(data->forks);
	free(data->philosophers);
}
