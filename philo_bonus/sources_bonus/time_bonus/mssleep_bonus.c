/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mssleep_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 19:40:10 by maolivei          #+#    #+#             */
/*   Updated: 2022/10/05 13:46:05 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	mssleep(time_t time_to_sleep)
{
	usleep(time_to_sleep * 1000);
}