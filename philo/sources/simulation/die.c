/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 18:34:53 by maolivei          #+#    #+#             */
/*   Updated: 2022/10/03 15:36:41 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	philo_die(t_philo *philo)
{
	if (has_simulation_ended(philo->data))
		return (FALSE);
	pthread_mutex_lock(&philo->data->end_lock);
	print_action(philo, "has died");
	philo->data->end_of_simulation = TRUE;
	pthread_mutex_unlock(&philo->data->end_lock);
	return (TRUE);
}
