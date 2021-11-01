/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghapa <bbc2788@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 14:37:59 by jonghapa          #+#    #+#             */
/*   Updated: 2021/10/20 00:46:07 by jonghapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(int argc, char	*argv[])
{
	if (argc > 0)
	{
		while (*argv[0])
		{
			ft_putchar(*argv[0]);
			argv[0]++;
		}
	}
	ft_putchar('\n');
}
