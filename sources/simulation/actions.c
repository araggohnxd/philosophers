/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 18:34:53 by maolivei          #+#    #+#             */
/*   Updated: 2022/09/27 20:54:35 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_die(t_philo *philo)
{
	if (philo->data->has_someone_died)
		return ;
	philo->data->has_someone_died = TRUE;
	print_action(philo, "has died");
}

void	philo_think(t_philo *philo)
{
	t_time	time_to_think;
	t_data	*data;

	data = philo->data;
	if (philo->data->has_someone_died)
		return ;
	print_action(philo, "is thinking");
	time_to_think = \
		(data->time_to_die - data->time_to_eat - data->time_to_sleep) / 2;
	if (time_to_think < 1)
		return ;
	sweet_dreams(philo, time_to_think);
}

void	philo_sleep(t_philo *philo)
{
	if (philo->data->has_someone_died)
		return ;
	print_action(philo, "is sleeping");
	sweet_dreams(philo, philo->data->time_to_sleep);
}
