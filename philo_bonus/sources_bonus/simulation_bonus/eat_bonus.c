/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 19:15:53 by maolivei          #+#    #+#             */
/*   Updated: 2022/10/05 00:24:29 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	drop_forks_back_to_table(t_philo *philo)
{
	sem_post(philo->data->forks);
	sem_post(philo->data->forks);
}

static int	take_forks_from_table(t_philo *philo)
{
	while (*(long *)philo->data->forks < 2)
	{
		if (get_elapsed_time(philo->last_meal) >= philo->data->time_to_die)
			return (philo_die(philo), -1);
		usleep(100);
	}
	sem_wait(philo->data->forks);
	print_action(philo, "has taken a fork");
	while (*(long *)philo->data->forks < 1)
	{
		if (get_elapsed_time(philo->last_meal) >= philo->data->time_to_die)
		{
			philo_die(philo);
			sem_post(philo->data->forks);
			return (-1);
		}
		usleep(100);
	}
	sem_wait(philo->data->forks);
	print_action(philo, "has taken a fork");
	return (0);
}

t_bool	philo_eat(t_philo *philo)
{
	if (has_simulation_ended(philo->data))
		return (FALSE);
	if (take_forks_from_table(philo) != 0)
		return (FALSE);
	print_action(philo, "is eating");
	if (sweet_dreams(philo, philo->data->time_to_eat) != 0)
		return (drop_forks_back_to_table(philo), FALSE);
	drop_forks_back_to_table(philo);
	++philo->done_meals;
	philo->last_meal = get_time_in_ms();
	if (philo->done_meals == philo->data->must_eat)
		return (FALSE);
	return (TRUE);
}
