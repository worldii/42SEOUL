/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghapa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 14:23:15 by jonghapa          #+#    #+#             */
/*   Updated: 2021/10/19 13:36:53 by jonghapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	check(int n, int queen[])
{
	int		i;

	i = 0;
	while (i < n)
	{
		if (queen[i] == queen[n])
			return (0);
		if (n - i == queen[n] - queen[i] || n - i == queen[i] - queen[n])
			return (0);
		i++;
	}
	return (1);
}

int	rec(int n, int queen[])
{
	int		cnt;
	int		i;

	cnt = 0;
	i = 0;
	if (n == 10)
	{
		while (i < 10)
			ft_putchar(queen[i++] + '0');
		write(1, "\n", 1);
		return (1);
	}
	else
	{
		while (i < 10)
		{
			queen[n] = i ;
			if (check(n, queen))
				cnt += rec(n + 1, queen);
			i++;
		}
	}
	return (cnt);
}

int	ft_ten_queens_puzzle(void)
{
	int		queen[10];

	return (rec(0, queen));
}
/*
int main(void) {
	ft_ten_queens_puzzle();
}*/
