/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghapa <bbc2788@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 13:40:15 by jonghapa          #+#    #+#             */
/*   Updated: 2021/10/12 13:41:55 by jonghapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	put_char(char c)
{
	write(1, &c, 1);
}

void	calculate(int nb)
{
	if (nb == 0)
	{
		return ;
	}
	calculate(nb / 10);
	put_char((nb % 10) + '0');
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
	}
	else if (nb >= 0)
	{	
		calculate(nb / 10);
		put_char((nb % 10) + '0');
	}
	else
	{
		put_char('-');
		calculate((-nb) / 10);
		put_char((-nb) % 10 + '0');
	}
}
