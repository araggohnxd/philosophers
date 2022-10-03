/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 18:47:42 by maolivei          #+#    #+#             */
/*   Updated: 2022/10/03 15:35:47 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_argument_value(char **argv)
{
	while (*(++argv))
	{
		if (!ft_is_valid_number_str(*argv))
		{
			printf("philo: `%s': invalid argument\n", *argv);
			return (-1);
		}
	}
	return (0);
}

static int	check_argument_count(int argc)
{
	if (argc < 5 || argc > 6)
	{
		if (argc < 5)
			printf("philo: too few arguments\n");
		if (argc > 6)
			printf("philo: too many arguments\n");
		printf("usage: "
			"<num-of-philos> "
			"<time-to-die> "
			"<time-to-eat> "
			"<time-to-sleep> "
			"[times-each-philo-must-eat]\n");
		return (-1);
	}
	return (0);
}

int	init_data(t_data *data, int argc, char **argv)
{
	if (check_argument_count(argc) != 0 || check_argument_value(argv) != 0)
		return (-1);
	memset(data, 0, sizeof(t_data));
	data->num_of_philosophers = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->must_eat = ft_atoi(argv[5]);
	else
		data->must_eat = -1;
	if (pthread_mutex_init(&data->end_lock, NULL) != 0)
		return (-1);
	if (pthread_mutex_init(&data->print_lock, NULL) != 0)
		return (-1);
	return (0);
}
