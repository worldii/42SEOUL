/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghapa <bbc2788@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 14:22:29 by jonghapa          #+#    #+#             */
/*   Updated: 2021/10/24 21:00:27 by jonghapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int			fileexists(int argc, char *argv[], int *fd, long long *num);
int			numexists(long long num);
long long	numcheck(char *str);

int	main(int argc, char *argv[])
{
	t_Dict		*head;
	int			fd;
	long long	num;
	int			sep;

	head = NULL;
	if (fileexists(argc, argv, &fd, &num) == 0)
		return (0);
	if (fileread(fd, &head) == 0)
		return (0);
	if (numexists(num) == 0)
		return (0);
	if (!check_num(num, head))
	{
		write(1, "Dict Error\n", 11);
		return (0);
	}
	sep = 0;
	print_num(num, &sep, head);
	write(1, "\n", 1);
	memory_deallocate(head);
}

int	fileexists(int argc, char *argv[], int *fd, long long *num)
{
	if (argc != 2 && argc != 3)
		*fd = -1;
	if (argc == 2)
	{
		*fd = open("numbers.dict", O_RDONLY);
		*num = numcheck(argv[1]);
	}
	else if (argc == 3)
	{
		*fd = open(argv[1], O_RDONLY);
		*num = numcheck(argv[2]);
	}
	if (*fd < 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	return (1);
}

int	numexists(long long num)
{
	if (num == -1 || num >= 4294967295 || num < 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	return (1);
}

long long	numcheck(char *str)
{
	long long	sum;

	sum = 0;
	if (*str == 0)
		return (-1);
	while (*str)
	{
		if (!('0' <= *str && *str <= '9'))
			return (-1);
		sum = sum * 10 + (*str++ - '0');
	}
	return (sum);
}
