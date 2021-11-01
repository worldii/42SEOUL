/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghapa <bbc2788@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 22:47:31 by jonghapa          #+#    #+#             */
/*   Updated: 2021/10/08 01:13:33 by jonghapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	put_char(char c)
{
	write (1, &c, 1);
}

void	print_num(int a, int b)
{
	put_char('0' + a / 10);
	put_char('0' + a % 10);
	put_char(' ');
	put_char('0' + b / 10);
	put_char('0' + b % 10);
	if (! (a == 98 && b == 99))
	{
		write(1, ", ", 2);
	}
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	while (a <= 99)
	{
		b = a + 1;
		while (b <= 99)
		{
			print_num(a, b);
			b++;
		}
		a++;
	}
}
