/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghapa <bbc2788@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 02:13:03 by jonghapa          #+#    #+#             */
/*   Updated: 2021/10/11 03:59:51 by jonghapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	changebig(char *str, int idx)
{
	str[idx] -= 'a' - 'A';
}

void	changesmall(char *str, int idx)
{
	str[idx] += 'a' - 'A';
}

int	checkblank(char *str, int idx)
{
	int	blank;

	blank = 0;
	if ('a' <= str[idx] && str[idx] <= 'z')
	{
		blank = 0;
	}
	else if ('A' <= str[idx] && str[idx] <= 'Z')
	{
		blank = 0;
	}
	else if ('0' <= str[idx] && str[idx] <= '9')
	{
		blank = 0;
	}
	else
	{
		blank = 1;
	}
	return (blank);
}

char	*ft_strcapitalize(char *str)
{
	int	idx;
	int	blank;

	idx = 0;
	blank = 1;
	while (str[idx] != '\0')
	{
		if (blank == 1)
		{
			if ('a' <= str[idx] && str[idx] <= 'z')
			{
				changebig(str, idx);
			}
		}
		else
		{
			if ('A' <= str[idx] && str[idx] <= 'Z')
			{
				changesmall(str, idx);
			}
		}
		blank = checkblank(str, idx);
		idx++;
	}
	return (str);
}
