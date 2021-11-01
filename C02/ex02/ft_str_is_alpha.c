/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghapa <bbc2788@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 19:49:41 by jonghapa          #+#    #+#             */
/*   Updated: 2021/10/10 20:11:21 by jonghapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int	idx;
	int	flag;

	idx = 0;
	flag = 1;
	while (str[idx] != '\0')
	{		
		if (!('a' <= str[idx] && str[idx] <= 'z'))
		{
			if (!('A' <= str[idx] && str[idx] <= 'Z'))
			{
				flag = 0 ;
			}
		}
		idx++;
	}
	return (flag);
}
