/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghapa <bbc2788@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 11:16:48 by jonghapa          #+#    #+#             */
/*   Updated: 2021/10/14 11:16:51 by jonghapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(unsigned char c)
{
	write(1, &c, 1);
}

void	change16(unsigned char num)
{
	char	*jinbub;
	int		div;
	int		rem;

	div = num / 16;
	rem = num % 16;
	jinbub = "0123456789abcdef";
	ft_putchar(jinbub[div]);
	ft_putchar(jinbub[rem]);
}

void	ft_putstr_non_printable(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx] != '\0')
	{
		if (!(32 <= str[idx] && str[idx] <= 126))
		{
			ft_putchar('\\');
			change16(str[idx]);
		}
		else
		{
			ft_putchar(str[idx]);
		}
		idx++;
	}
}
