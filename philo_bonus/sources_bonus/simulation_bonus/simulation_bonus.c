/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 16:59:06 by maolivei          #+#    #+#             */
/*   Updated: 2022/10/04 22:02:02 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	cogito_ergo_sum(t_philo *philo)
{
	if (philo->philo_id % 2)
		usleep(500);
	while (philo_eat(philo) && philo_sleep(philo) && philo_think(philo))
		continue ;
	destroy_philo(philo->data);
	exit(EXIT_SUCCESS);
}

void	run_simulation(t_data *data)
{
	size_t	index;
	pid_t	current_pid;

	data->kickstart = get_time_in_ms();
	index = 0;
	while (index < data->num_of_philosophers)
	{
		data->philosophers[index].last_meal = data->kickstart;
		current_pid = fork();
		if (current_pid == 0)
			cogito_ergo_sum(&data->philosophers[index]);
		else if (current_pid < 0)
			break ;
		else
			data->philosophers[index].process_id = current_pid;
		++index;
	}
	index = 0;
	while (index < data->num_of_philosophers)
		waitpid(data->philosophers[index++].process_id, NULL, 0);
}
