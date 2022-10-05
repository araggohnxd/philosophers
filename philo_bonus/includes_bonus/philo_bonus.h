/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 17:49:11 by maolivei          #+#    #+#             */
/*   Updated: 2022/10/05 13:45:47 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include "internals_bonus.h"

/* Init */
int		init_data(t_data *data, int argc, char **argv);
int		init_philos(t_data *data);

/* Simulation */
void	run_simulation(t_data *data);
t_bool	has_simulation_ended(t_data *data);

/* Actions */
t_bool	philo_eat(t_philo *philo);
t_bool	philo_sleep(t_philo *philo);
t_bool	philo_think(t_philo *philo);
t_bool	philo_die(t_philo *philo);

/* Destroy */
void	destroy_data(t_data *data);
void	destroy_philo(t_data *data);

/* Time */
void	mssleep(time_t time_to_sleep);
time_t	get_time_in_ms(void);
time_t	get_elapsed_time(time_t then);

/* Utilities */
int		ft_atoi(const char *nptr);
int		ft_strcmp(const char *s1, const char *s2);
t_bool	ft_isdigit(int c);
t_bool	ft_is_valid_number_str(const char *str);

/* Thread utilities */
int		sweet_dreams(t_philo *philo, time_t sleep_time);
void	print_action(t_philo *philo, const char *action);

#endif /* PHILO_BONUS_H */
