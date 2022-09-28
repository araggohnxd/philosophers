/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 19:15:53 by maolivei          #+#    #+#             */
/*   Updated: 2022/09/27 20:54:35 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	drop_forks_back_to_table(t_philo *philo)
{
	if (philo->fork_left->is_locked)
		ft_mutex_unlock(philo->fork_left);
	if (philo->fork_right->is_locked)
		ft_mutex_unlock(philo->fork_right);
	return (-1);
}

static int	take_a_fork(t_philo *philo, t_mutex *fork)
{
	while (fork->is_locked)
	{
		if (philo->data->has_someone_died)
			return (drop_forks_back_to_table(philo));
		if (get_elapsed_time(philo->last_meal) >= philo->data->time_to_die)
		{
			philo_die(philo);
			return (drop_forks_back_to_table(philo));
		}
		usleep(100);
	}
	if (philo->data->has_someone_died)
		return (drop_forks_back_to_table(philo));
	ft_mutex_lock(fork);
	print_action(philo, "has taken a fork");
	return (0);
}

static int	take_forks_from_table(t_philo *philo)
{
	while (philo->fork_left->is_locked || philo->fork_right->is_locked)
	{
		if (philo->data->has_someone_died)
			return (-1);
		if (get_elapsed_time(philo->last_meal) >= philo->data->time_to_die)
			return (philo_die(philo), -1);
		usleep(100);
	}
	if (take_a_fork(philo, philo->fork_left) != 0)
		return (-1);
	if (take_a_fork(philo, philo->fork_right) != 0)
		return (-1);
	return (0);
}

void	philo_eat(t_philo *philo)
{
	if (philo->data->has_someone_died)
		return ;
	if (take_forks_from_table(philo) != 0)
		return ;
	++philo->done_meals;
	philo->last_meal = get_time_in_ms();
	if (philo->data->has_someone_died)
	{
		drop_forks_back_to_table(philo);
		return ;
	}
	print_action(philo, "is eating");
	sweet_dreams(philo, philo->data->time_to_eat);
	drop_forks_back_to_table(philo);
}
