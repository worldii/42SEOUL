/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghapa <bbc2788@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 03:26:44 by jonghapa          #+#    #+#             */
/*   Updated: 2021/10/19 13:16:41 by jonghapa         ###   ########.fr       */
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
	while ((long long)num * num <= nb)
	{
		if (nb % num == 0)
			return (0);
		num++;
	}
	return (1);
}
/*
int main(void)
{
	int num = ft_is_prime(4);
	printf("%d", num);
}*/
