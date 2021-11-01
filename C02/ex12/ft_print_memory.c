/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghapa <bbc2788@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 02:57:13 by jonghapa          #+#    #+#             */
/*   Updated: 2021/10/15 17:02:09 by jonghapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

char	*g_jinbub = "0123456789abcdef";

void	calculate_addr(long long addr, int len)
{
	if (len == 16)
	{	
		return ;
	}
	calculate_addr(addr / 16, len + 1);
	write(1, &g_jinbub[addr % 16], 1);
}

void	printascii(void *addr, int len)
{
	int				idx;
	unsigned char	*ptr;

	ptr = (unsigned char *) addr;
	idx = 0;
	while (idx < len)
	{
		if (idx % 2 == 0)
			write(1, " ", 1);
		write(1, &g_jinbub[ptr[idx] / 16], 1);
		write(1, &g_jinbub[ptr[idx] % 16], 1);
		idx++;
	}
	while (idx < 16)
	{
		if (idx % 2 == 0)
			write(1, " ", 1);
		write(1, "  ", 2);
		idx++;
	}
}

void	non_print(unsigned char *ptr, int idx)
{
	if (!(32 <= ptr[idx] && ptr[idx] <= 126))
	{
		write(1, ".", 1);
	}
	else
	{
		write(1, &ptr[idx], 1);
	}
}

void	printchar(void *addr, int len)
{
	int				idx;
	unsigned char	*ptr;

	idx = 0;
	ptr = (unsigned char *) addr;
	while (idx < len)
	{
		non_print(ptr, idx);
		idx++;
	}
	write(1, "\n", 1);
}	

void	*ft_print_memory(void *addr, unsigned int size)
{
	int				idx;
	unsigned char	*tempaddr;
	int				len;

	len = (int) size;
	idx = 0;
	tempaddr = (unsigned char *) addr;
	while (size > 0)
	{
		if (size / 16 > 0)
			len = 16;
		else
			len = size ;
		calculate_addr((long long)tempaddr + idx, 0);
		write(1, ":", 1);
		printascii(tempaddr + idx, len);
		write(1, " ", 1);
		printchar(tempaddr + idx, len);
		idx = idx + 16;
		size -= len;
	}
	return (addr);
}
