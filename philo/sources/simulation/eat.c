/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 19:15:53 by maolivei          #+#    #+#             */
/*   Updated: 2022/10/05 13:50:13 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	lonely_philo(t_philo *philo)
{
	print_action(philo, "has taken a fork");
	mssleep(philo->data->time_to_die);
	philo_die(philo);
}

static void	drop_forks_back_to_table(t_philo *philo)
{
	pthread_mutex_unlock(philo->fork_right);
	pthread_mutex_unlock(philo->fork_left);
}

static int	take_forks_from_table(t_philo *philo)
{
	t_mutex	*first_to_take;
	t_mutex	*last_to_take;

	if (philo->philo_id % 2 == 0)
	{
		first_to_take = philo->fork_right;
		last_to_take = philo->fork_left;
	}
	else
	{
		first_to_take = philo->fork_left;
		last_to_take = philo->fork_right;
	}
	if (has_simulation_ended(philo->data))
		return (-1);
	if (get_elapsed_time(philo->last_meal) >= philo->data->time_to_die)
		return (philo_die(philo), -1);
	pthread_mutex_lock(first_to_take);
	print_action(philo, "has taken a fork");
	pthread_mutex_lock(last_to_take);
	print_action(philo, "has taken a fork");
	return (0);
}

t_bool	philo_eat(t_philo *philo)
{
	if (philo->data->num_of_philosophers == 1)
		return (lonely_philo(philo), -1);
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
