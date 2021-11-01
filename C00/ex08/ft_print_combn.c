/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghapa <bbc2788@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:29:00 by jonghapa          #+#    #+#             */
/*   Updated: 2021/10/09 01:10:43 by jonghapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	put_char(char c)
{
	write(1, &c, 1);
}

int	check_max(int *arr, int n)
{
	int	num;
	int	maxflag;
	int	idx;

	num = 9;
	maxflag = 1;
	idx = n - 1;
	while (idx >= 0)
	{
		if (! (num == arr[idx]))
		{
			maxflag = 0;
			break ;
		}
		num--;
		idx--;
	}
	return (maxflag);
}

void	recur(int cnt, int nownum, int n, int *arr)
{	
	int	i;
	int	maxflag;

	if (cnt == n)
	{	
		i = 0;
		while (i <= n - 1)
		{
			put_char(arr[i] + '0');
			i++;
		}
		maxflag = check_max(arr, n);
		if (!maxflag)
		{
			write(1, ", ", 2);
		}
		return ;
	}
	i = nownum;
	while (i <= 9)
	{
		arr[cnt] = i;
		recur(cnt + 1, i + 1, n, arr);
		i++;
	}
}

void	ft_print_combn(int n)
{
	int	array[11];

	recur(0, 0, n, array);
}

/*
int main(void) {
ft_print_combn(9);
}*/
