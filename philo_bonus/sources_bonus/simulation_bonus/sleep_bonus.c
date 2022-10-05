/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 18:34:53 by maolivei          #+#    #+#             */
/*   Updated: 2022/10/04 19:00:27 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

t_bool	philo_sleep(t_philo *philo)
{
	if (has_simulation_ended(philo->data))
		return (FALSE);
	print_action(philo, "is sleeping");
	if (sweet_dreams(philo, philo->data->time_to_sleep) != 0)
		return (FALSE);
	return (TRUE);
}
