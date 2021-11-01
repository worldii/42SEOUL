/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghapa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:07:24 by jonghapa          #+#    #+#             */
/*   Updated: 2021/10/15 18:40:50 by jonghapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	char	*ftmp;
	char	*stmp;

	if (*to_find == 0)
		return (str);
	while (*str)
	{
		ftmp = to_find;
		stmp = str;
		while (*stmp && *ftmp == *stmp)
		{
			ftmp++;
			stmp++;
		}
		if (*ftmp == 0)
			return (str);
		str++;
	}
	return (0);
}
