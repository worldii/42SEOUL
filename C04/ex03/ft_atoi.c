/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghapa <bbc2788@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 13:44:35 by jonghapa          #+#    #+#             */
/*   Updated: 2021/10/21 21:50:04 by jonghapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	checkmin(int idx, char *str)
{
	char	*min;
	int		midx;

	midx = 0;
	min = "2147483648";
	while (str[idx] != '\0')
	{
		if (str[idx++] != min[midx++])
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

int	calculatesum(int i, int len, char *str)
{
	int	sum;

	sum = 0;
	while (i < len)
	{
		if (! ('0' <= str[i] && str[i] <= '9'))
		{
			break ;
		}
		sum = sum * 10 + str[i] - '0';
		i++;
	}
	return (sum);
}

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

int	ft_atoi(char *str)
{
	int	len;
	int	buho;
	int	i;
	int	sum;

	len = 0;
	i = 0;
	sum = 0;
	while (ft_isspace(str, i) == 1)
	{
		i++;
	}
	buho = checkbuho(&i, str);
	if (checkmin(i, str) == 1)
		return (-2147483648);
	while (str[len] != '\0')
	{
		len++;
	}	
	sum = calculatesum(i, len, str);
	if (buho == 0)
	{
		sum = -sum;
	}
	return (sum);
}
