/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghapa <bbc2788@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 02:53:32 by jonghapa          #+#    #+#             */
/*   Updated: 2021/10/18 01:24:38 by jonghapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	ans;
	int	num;

	ans = 1;
	num = 1;
	if (power < 0)
		return (0);
	while (num <= power)
	{
		ans *= nb;
		num++;
	}
	return (ans);
}
