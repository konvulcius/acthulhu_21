/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_figure_to_buff.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliza <lliza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 17:40:07 by lliza             #+#    #+#             */
/*   Updated: 2019/11/21 17:40:10 by lliza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		ft_add_figure_to_buff(char *buff, int n)
{
	int sum;

	sum = n + (*buff ? *buff - '0' : 0);
	if (sum > 9)
	{
		*buff = sum % 10 + '0';
		ft_add_figure_to_buff(buff + 1, sum / 10);
	}
	else
		*buff = sum + '0';
}
