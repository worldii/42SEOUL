/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghapa <bbc2788@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 22:28:56 by jonghapa          #+#    #+#             */
/*   Updated: 2021/10/23 11:58:27 by jonghapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int			ft_isspace(char *str, int idx);
int			basecheck(char *base, int *baselen);
long long	calculatesum(char *nbr, int baselen1, int sign, char *base_from);

long long	base_from_num(char *nbr, char *base_from, int baselen1)
{
	int			sign;
	int			idx;

	sign = 1;
	idx = 0;
	while (ft_isspace(nbr, idx))
		idx++;
	nbr = nbr + idx;
	while (*nbr == '+' || *nbr == '-')
	{
		if (*nbr++ == '-')
			sign *= -1;
	}
	return (calculatesum(nbr, baselen1, sign, base_from));
}

int	ft_base_strlen(int baselen, long long num)
{
	int	ans;

	if (num == 0)
		return (1);
	ans = 0;
	if (num < 0)
		ans++;
	while (num)
	{
		num /= baselen;
		ans++;
	}
	return (ans);
}

char	*num_base_to(long long num, char *base_to, int baselen2)
{
	char		*temp;
	int			numlen;
	long long	tempnum;

	numlen = ft_base_strlen(baselen2, num);
	temp = (char *) malloc (numlen + 1);
	if (temp == NULL)
		return (0);
	tempnum = num;
	if (num < 0)
		tempnum = -num;
	temp[numlen] = 0;
	if (tempnum == 0 && numlen == 1)
	{
		temp[0] = base_to[0];
		return (temp);
	}
	while (tempnum)
	{
		temp[--numlen] = base_to[tempnum % baselen2];
		tempnum /= baselen2;
	}
	if (num < 0)
		temp[0] = '-';
	return (temp);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int			baselen2;
	int			baselen1;
	long long	tempnum;

	if (!basecheck(base_from, &baselen1) || !basecheck(base_to, &baselen2))
		return (0);
	tempnum = base_from_num(nbr, base_from, baselen1);
	return (num_base_to(tempnum, base_to, baselen2));
}
