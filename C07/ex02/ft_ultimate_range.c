/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghapa <bbc2788@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 01:49:20 by jonghapa          #+#    #+#             */
/*   Updated: 2021/10/21 22:17:55 by jonghapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	len;

	i = 0;
	len = max - min;
	if (min >= max)
		return (0);
	*range = (int *) malloc (sizeof(int) * len);
	if (!*range)
		return (-1);
	while (min < max)
	{
		(*range)[i] = min++;
		i++;
	}
	return (len);
}
/*
int main(void)
{
	int *range;
	printf("%d", ft_ultimate_range(&range, 0, 3));
	for (int i = 0 ; i < 3; i++)
	{
		printf("%d", range[i]);
	}
}*/
