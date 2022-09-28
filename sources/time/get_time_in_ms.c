/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time_in_ms.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 16:27:26 by maolivei          #+#    #+#             */
/*   Updated: 2022/09/26 16:57:14 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_time	get_time_in_ms(void)
{
	t_timeval	timeval;

	gettimeofday(&timeval, NULL);
	return (((timeval.tv_sec * 1000000) + timeval.tv_usec) / 1000);
}
