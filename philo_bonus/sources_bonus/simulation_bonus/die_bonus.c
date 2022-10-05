/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 18:34:53 by maolivei          #+#    #+#             */
/*   Updated: 2022/10/05 00:12:33 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

t_bool	philo_die(t_philo *philo)
{
	if (has_simulation_ended(philo->data))
		return (FALSE);
	sem_wait(philo->data->end_lock);
	sem_post(philo->data->end_of_simulation);
	print_action(philo, "died");
	sem_post(philo->data->end_lock);
	return (TRUE);
}
