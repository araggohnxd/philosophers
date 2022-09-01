/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 18:47:42 by maolivei          #+#    #+#             */
/*   Updated: 2022/09/01 18:47:51 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	check_argument_value(char **argv)
{
	size_t	i;
	size_t	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
			{
				printf("philo: %s: invalid argument\n", argv[i]);
				exit(EXIT_FAILURE);
			}
			++j;
		}
		++i;
	}
}

static void	check_argument_count(int argc)
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
		exit(EXIT_FAILURE);
	}
}

void	init_data(t_data *data, int argc, char **argv)
{
	check_argument_count(argc);
	check_argument_value(argv);
	data->number_of_philosophers = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->must_eat = 0;
	if (argc == 6)
		data->must_eat = ft_atoi(argv[5]);
}
