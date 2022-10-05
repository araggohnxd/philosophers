/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_valid_number_str_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 10:45:25 by maolivei          #+#    #+#             */
/*   Updated: 2022/10/04 19:00:27 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

t_bool	ft_is_valid_number_str(const char *str)
{
	const char	*start = str;

	if (*str == '-')
		return (FALSE);
	if (*str == '+')
		++str;
	while (*str)
		if (!ft_isdigit(*str++))
			return (FALSE);
	if (ft_atoi(start) == 0)
		return (FALSE);
	return (TRUE);
}
