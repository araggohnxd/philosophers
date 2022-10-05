/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 21:14:02 by maolivei          #+#    #+#             */
/*   Updated: 2022/10/04 21:54:19 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

t_bool	has_simulation_ended(t_data *data)
{
	t_bool	end_of_simulation;

	sem_wait(data->end_lock);
	end_of_simulation = *(long *)data->end_of_simulation;
	sem_post(data->end_lock);
	return (end_of_simulation);
}

void	print_action(t_philo *philo, const char *action)
{
	const time_t	elapsed_time = get_elapsed_time(philo->data->kickstart);

	if (ft_strcmp(action, "died") != 0 && has_simulation_ended(philo->data))
		return ;
	sem_wait(philo->data->print_lock);
	printf("%5ld %3d %s\n", elapsed_time, (philo->philo_id + 1), action);
	sem_post(philo->data->print_lock);
}

int	sweet_dreams(t_philo *philo, time_t sleep_time)
{
	const time_t	started_sleeping = get_time_in_ms();
	time_t			current_time_slept;

	current_time_slept = 0;
	while (current_time_slept < sleep_time)
	{
		if (has_simulation_ended(philo->data))
			return (-1);
		if (get_elapsed_time(philo->last_meal) >= philo->data->time_to_die)
			return (philo_die(philo), -1);
		usleep(100);
		current_time_slept = get_elapsed_time(started_sleeping);
	}
	return (0);
}
