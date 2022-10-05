/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 17:49:07 by maolivei          #+#    #+#             */
/*   Updated: 2022/10/04 21:54:24 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (init_data(&data, argc, argv) != 0)
		return (EXIT_FAILURE);
	if (init_philos(&data) != 0)
		return (EXIT_FAILURE);
	run_simulation(&data);
	destroy_data(&data);
	return (EXIT_SUCCESS);
}
