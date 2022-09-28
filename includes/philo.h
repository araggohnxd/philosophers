/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 17:49:11 by maolivei          #+#    #+#             */
/*   Updated: 2022/09/27 21:05:48 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "internals.h"

/* Init */
int		init_data(t_data *data, int argc, char **argv);
int		init_forks(t_data *data);
int		init_philos(t_data *data);

/* Simulation */
void	run_simulation(t_data *data);

/* Thread routine */
void	*cogito_ergo_sum(void *data);

/* Actions */
void	philo_eat(t_philo *philo);
void	philo_sleep(t_philo *philo);
void	philo_think(t_philo *philo);
void	philo_die(t_philo *philo);

/* Destroy */
void	destroy_data(t_data *data);

/* Time */
void	mssleep(t_time time_to_sleep);
t_time	get_time_in_ms(void);
t_time	get_elapsed_time(t_time then);

/* Utilities */
int		ft_atoi(const char *nptr);
t_bool	ft_isdigit(int c);
t_bool	ft_is_valid_number_str(const char *str);

/* Mutex utilities */
void	ft_mutex_lock(t_mutex *mutex);
void	ft_mutex_unlock(t_mutex *mutex);

/* Actions utilities */
void	sweet_dreams(t_philo *philo, t_time sleep_time);
void	print_action(t_philo *philo, const char *action);

#endif /* PHILO_H */
