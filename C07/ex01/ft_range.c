/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghapa <bbc2788@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 01:20:48 by jonghapa          #+#    #+#             */
/*   Updated: 2021/10/21 22:33:25 by jonghapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	len;
	int	*temp;
	int	i;

	i = 0;
	if (min >= max)
		return (NULL);
	len = max - min;
	temp = (int *) malloc (sizeof(int) * len);
	if (temp == NULL)
		return (0);
	while (len--)
		temp[i++] = min++;
	return (temp);
}
