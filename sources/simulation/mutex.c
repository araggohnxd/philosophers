/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 19:30:21 by maolivei          #+#    #+#             */
/*   Updated: 2022/09/26 19:30:27 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_mutex_unlock(t_mutex *mutex)
{
	pthread_mutex_unlock(&mutex->mutex);
	mutex->is_locked = FALSE;
}

void	ft_mutex_lock(t_mutex *mutex)
{
	pthread_mutex_lock(&mutex->mutex);
	mutex->is_locked = TRUE;
}
