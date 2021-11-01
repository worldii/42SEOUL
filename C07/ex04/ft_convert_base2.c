/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghapa <bbc2788@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 01:53:20 by jonghapa          #+#    #+#             */
/*   Updated: 2021/10/23 02:14:38 by jonghapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_isspace(char *str, int idx)
{
	if (str[idx] == '\t')
		return (1);
	if (str[idx] == '\n')
		return (1);
	if (str[idx] == ' ')
		return (1);
	if (str[idx] == '\f')
		return (1);
	if (str[idx] == '\v')
		return (1);
	if (str[idx] == '\r')
		return (1);
	return (0);
}

int	basecheck(char *base, int *baselen)
{
	int	idx;
	int	ascii[257];

	idx = 0;
	while (idx < 256)
		ascii[idx++] = 0;
	idx = 0;
	while (base[idx] != '\0')
	{
		ascii[(int) base[idx]]++;
		if (base[idx] == '+' || base[idx] == '-' || ft_isspace(base, idx) == 1)
			return (0);
		idx++;
	}
	*baselen = idx;
	if (idx <= 1)
		return (0);
	while (idx < 256)
	{
		if (ascii[idx++] > 1)
			return (0);
	}
	return (1);
}

long long	calculatesum(char *nbr, int baselen1, int sign, char *base_from)
{
	long long	ans;
	int			idx;

	ans = 0;
	while (*nbr)
	{
		idx = -1;
		while (++idx < baselen1)
		{
			if (base_from[idx] == *nbr)
				break ;
		}
		if (idx == baselen1)
			break ;
		ans = ans * baselen1 + idx * sign;
		nbr++;
	}
	return (ans);
}	
