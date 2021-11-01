/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghapa <bbc2788@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 08:15:56 by jonghapa          #+#    #+#             */
/*   Updated: 2021/10/24 08:25:16 by jonghapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
/////기본적 함수들////
int	ft_strcmp(char *str1, char*str2)
{
	while (*str1 && *str2)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*str)
	{
		str++;
		len++;
	}
	return (len);
}

int	is_space(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	else if (c == '\v' || c == '\f' || c == '\r')
		return (1);
	else
	{
		return (0);
	}
}

long long	ft_atoi(char *str)
{
	long long	sum;

	sum = 0;
	while (*str && is_space(*str) == 1)
		++str;
	if (*str == '-')
		return (-1);
	else if (*str == '+')
		str++;
	if (*str == '+' || *str == '-')
		return (0);
	while (*str && ('0' <= *str && *str <= '9'))
		sum = sum * 10 + (*str++ - '0');
	return (sum);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}
////////////////////
