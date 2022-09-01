/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 17:49:11 by maolivei          #+#    #+#             */
/*   Updated: 2022/09/01 19:01:31 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "internals.h"

/* Init */
int	init_data(t_data *data, int argc, char **argv);

/* Utils */
int	ft_atoi(const char *nptr);
int	ft_isdigit(int c);

#endif /* PHILO_H */
