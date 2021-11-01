/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghapa <bbc2788@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 02:52:59 by jonghapa          #+#    #+#             */
/*   Updated: 2021/10/18 01:43:11 by jonghapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	else if (power == 0)
	{	
		return (1);
	}
	else
	{
		return (ft_recursive_power(nb, power - 1) * nb);
	}
}
/*
int main(void) {
	int num = ft_recursive_power(3,2);
	printf("%d", num);
}*/
