/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghapa <bbc2788@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 14:06:40 by jonghapa          #+#    #+#             */
/*   Updated: 2021/10/24 17:52:15 by jonghapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

///// 숫자 계산 함수들 
int	getrange(int num)
{
	if (num >= 1000000000)
		return (1000000000);
	if (num >= 1000000)
		return (1000000);
	if (num >= 1000)
		return (1000);
	if (num >= 100)
		return (100);
	if (num >= 90)
		return (90);
	if (num >= 80)
		return (80);
	if (num >= 70)
		return (70);
	if (num >= 60)
		return (60);
	else
	{
		return (getrange2(num));
	}
}

int	getrange2(int num)
{
	if (num >= 50)
		return (50);
	if (num >= 40)
		return (40);
	if (num >= 30)
		return (30);
	if (num >= 20)
		return (20);
	if (num <= 20)
		return (num);
	else
	{
		return (0);
	}
}

int	check_dict(t_Dict *head, long long num, int flag)
{
	t_Dict	*cur;

	cur = head;
	while (cur != NULL)
	{
		if (ft_atoi(cur->key) == num)
		{
			if (flag == 1)
				ft_putstr(cur->value);
			return (1);
		}
		cur = cur -> next;
	}
	return (0);
}

int	check_num(long long n, t_Dict *head)
{
	int	range;

	if (n == 0)
		return (1);
	range = getrange(n);
	if (range >= 100 && check_num(n / range, head) == 1)
		return (1);
	if (check_dict(head, range, 0) == 1)
		return (1);
	if (range != 0 && n % range != 0)
	{
		if (check_num(n % range, head) == 1)
			return (1);
	}
	return (0);
}

void	print_num(long long n, int *sep, t_Dict *head)
{
	int	range;

	range = getrange(n);
	if (range >= 100)
		print_num(n / range, sep, head);
	if (*sep != 0)
		write(1, " ", 1);
	*sep = 1;
	check_dict(head, range, 1);
	if (range != 0 && n % range != 0)
		print_num(n % range, sep, head);
}	
///////
