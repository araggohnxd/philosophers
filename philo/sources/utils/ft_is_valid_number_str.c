/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_valid_number_str.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 10:45:25 by maolivei          #+#    #+#             */
/*   Updated: 2022/09/27 21:28:21 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
