/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliza <robotizac@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 12:43:52 by lliza             #+#    #+#             */
/*   Updated: 2020/05/29 01:57:16 by lliza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int n)
{
	int		left;
	int		right;
	int		mid;

	left = 0;
	right = n;
	mid = 0;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (mid * mid == n)
			return (mid);
		if (mid * mid > n)
			right = mid - 1;
		if (mid * mid < n)
			left = mid + 1;
	}
	return (mid);
}
