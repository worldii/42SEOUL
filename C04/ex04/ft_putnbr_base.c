/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghapa <bbc2788@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 15:35:57 by jonghapa          #+#    #+#             */
/*   Updated: 2021/10/21 19:50:33 by jonghapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>

int	getlength(char *base)
{
	int	idx;

	idx = 0;
	while (base[idx] != '\0')
	{
		idx++;
	}
	return (idx);
}

int	basecheck(char *base)
{
	int	idx;
	int	ascii[257];

	idx = 0;
	while (idx < 256)
	{
		ascii[idx++] = 0;
	}
	idx = 0;
	while (base[idx] != '\0')
	{
		ascii[(int) base[idx]]++;
		if (base[idx] == '+' || base[idx] == '-')
			return (0);
		idx++;
	}
	if (idx <= 1)
		return (0);
	idx = 0;
	while (idx < 256)
	{
		if (ascii[idx++] > 1)
			return (0);
	}
	return (1);
}

void	calculate(int nbr, char *base, int baselen)
{
	if (nbr == 0)
		return ;
	calculate(nbr / baselen, base, baselen);
	write(1, &base[nbr % baselen], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int			baselen;
	long long	tmp;

	tmp = nbr;
	if (basecheck(base) == 0)
		return ;
	baselen = getlength(base);
	if (tmp >= 0)
	{
		calculate(tmp / baselen, base, baselen);
		write(1, &base[tmp % baselen], 1);
	}
	else
	{
		write(1, "-", 1);
		calculate(-tmp / baselen, base, baselen);
		write(1, &base[-tmp % baselen], 1);
	}	
}
/*
int main(void){
	ft_putnbr_base(-2147483648, "0123456789");
} */
