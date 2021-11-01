/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghapa <bbc2788@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 19:54:40 by jonghapa          #+#    #+#             */
/*   Updated: 2021/10/21 22:05:23 by jonghapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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

int	checkbuho(int *i, char *str)
{
	int	plus;
	int	minus;

	plus = 0;
	minus = 0;
	while (1)
	{
		if (str[*i] == '+')
			plus++;
		else if (str[*i] == '-')
			minus++;
		else
			break ;
		(*i)++;
	}
	return (minus % 2 == 0);
}

int	matchidx(char c, char *base, int baselen)
{
	int	idx;

	idx = 0;
	while (idx < baselen)
	{
		if (c == base[idx])
			return (idx);
		idx++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	baselen;
	int	i;
	int	sum;
	int	buho;
	int	temp;

	sum = 0;
	i = 0;
	baselen = 0;
	if (basecheck(base, &baselen) == 0)
		return (0);
	while (ft_isspace(str, i) == 1)
		i++;
	buho = checkbuho(&i, str);
	while (str[i] != '\0')
	{	
		temp = matchidx(str[i++], base, baselen);
		if (temp == -1)
			break ;
		sum = sum * baselen + temp;
	}
	if (buho == 0)
		sum = -sum;
	return (sum);
}
