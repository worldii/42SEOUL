/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghapa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 11:45:15 by jonghapa          #+#    #+#             */
/*   Updated: 2021/10/19 13:18:52 by jonghapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	num;

	if (nb <= 1)
		return (0);
	if (nb <= 3)
		return (1);
	num = 2;
	while ((long long) num * num <= nb)
	{
		if (nb % num == 0)
			return (0);
		num++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int	num;

	num = nb;
	while (1)
	{
		if (ft_is_prime(num))
			return (num);
		num++;
	}
}
