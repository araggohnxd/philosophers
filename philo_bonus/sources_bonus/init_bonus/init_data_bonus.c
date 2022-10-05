/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 18:47:42 by maolivei          #+#    #+#             */
/*   Updated: 2022/10/05 13:38:08 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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

static sem_t	*create_semaphore(const char *name, unsigned int value)
{
	sem_t	*new_semaphore;

	sem_unlink(name);
	new_semaphore = sem_open(name, O_CREAT, 0644, value);
	if (new_semaphore == SEM_FAILED)
	{
		write(2, "philo: failed to open semaphore\n", 33);
		exit(EXIT_FAILURE);
	}
	return (new_semaphore);
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
	data->forks = create_semaphore(SEM_FORKS, data->num_of_philosophers);
	data->end_lock = create_semaphore(SEM_END, 1);
	data->print_lock = create_semaphore(SEM_PRINT, 1);
	data->end_of_simulation = create_semaphore(SEM_OVER, 0);
	return (0);
}
