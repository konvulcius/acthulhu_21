/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acthulhu <marvin@fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 21:15:25 by acthulhu          #+#    #+#             */
/*   Updated: 2020/04/21 15:10:07 by acthulhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

int		ft_only_dig_validation(char *string)
{
	int		count;

	if (!string)
		return (0);
	if (*string == '-' || *string == '+')
		string++;
	count = 0;
	while (*string)
	{
		if (count == 11 || !ft_isdigit(*string))
			return (0);
		++count;
		if (count == 1 && !ft_strncmp(string, "0", 1))
			--count;
		++string;
	}
	if (count == 0 && (*(string - 1) - '0'))
		return (0);
	return (1);
}

int		ft_digit_compare(long long value)
{
	if (value > MAXIMAL_INT || value < -MAXIMAL_INT - 1)
		return (0);
	return (1);
}

size_t	ft_parse_room(char *line)
{
	size_t	count;

	count = 0;
	if (*line == 'L')
		ft_error_here();
	while (*line)
	{
		while (!ft_isspace(*line) && *line)
			line++;
		if (ft_isspace(*line) || !*line)
			count++;
		while (ft_isspace(*line) && *line)
			line++;
	}
	if (count != 1 && count != 3)
		ft_error_here();
	if (count == 3)
		return (1);
	else
		return (0);
}
