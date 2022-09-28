/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 11:54:34 by maolivei          #+#    #+#             */
/*   Updated: 2022/09/27 21:04:18 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_forks(t_data *data)
{
	size_t	index;

	data->forks = malloc(sizeof(t_mutex) * data->num_of_philosophers);
	if (!data->forks)
		return (-1);
	index = 0;
	while (index < data->num_of_philosophers)
	{
		if (pthread_mutex_init(&(data->forks[index].mutex), NULL) != 0)
			return (free(data->forks), -1);
		data->forks[index].is_locked = FALSE;
		++index;
	}
	return (0);
}
