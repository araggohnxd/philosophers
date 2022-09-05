/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 17:49:11 by maolivei          #+#    #+#             */
/*   Updated: 2022/09/05 11:00:16 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "internals.h"

/* Init */
t_status	init_data(t_data *data, int argc, char **argv);

/* Utils */
int			ft_atoi(const char *nptr);
t_bool		ft_isdigit(int c);
t_bool		ft_is_valid_number_str(const char *str);

#endif /* PHILO_H */
