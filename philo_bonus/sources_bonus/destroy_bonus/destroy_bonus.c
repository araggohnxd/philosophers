/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 12:18:16 by maolivei          #+#    #+#             */
/*   Updated: 2022/10/05 13:39:00 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	destroy_semaphore(const char *name, sem_t *semaphore)
{
	sem_close(semaphore);
	sem_unlink(name);
}

void	destroy_philo(t_data *data)
{
	sem_close(data->forks);
	sem_close(data->end_lock);
	sem_close(data->print_lock);
	sem_close(data->end_of_simulation);
	free(data->philosophers);
}

void	destroy_data(t_data *data)
{
	destroy_semaphore(SEM_FORKS, data->forks);
	destroy_semaphore(SEM_END, data->end_lock);
	destroy_semaphore(SEM_PRINT, data->print_lock);
	destroy_semaphore(SEM_OVER, data->end_of_simulation);
	free(data->philosophers);
}
