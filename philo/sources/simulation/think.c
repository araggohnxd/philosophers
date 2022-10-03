/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 18:34:53 by maolivei          #+#    #+#             */
/*   Updated: 2022/10/03 11:50:53 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	philo_think(t_philo *philo)
{
	if (has_simulation_ended(philo->data))
		return (FALSE);
	print_action(philo, "is thinking");
	return (TRUE);
}
