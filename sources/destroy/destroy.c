/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 12:18:16 by maolivei          #+#    #+#             */
/*   Updated: 2022/09/27 20:45:49 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_data(t_data *data)
{
	size_t	index;

	index = 0;
	while (index < data->num_of_philosophers)
		pthread_mutex_destroy(&(data->forks[index++].mutex));
	free(data->forks);
	free(data->philosophers);
}
