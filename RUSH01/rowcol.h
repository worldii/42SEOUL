/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rowcol.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghapa <bbc2788@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 23:34:22 by jonghapa          #+#    #+#             */
/*   Updated: 2021/10/17 23:34:25 by jonghapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROWCOL_H
# define ROWCOL_H
# include "header.h"

int		rowcol_check(int cnt, int num, int map[][4]);
int		rowleft_check(int cnt, int num, int map[][4], int *constraint);
int		rowright_check(int cnt, int num, int map[][4], int *constraint);
int		coldown_check(int cnt, int num, int map[][4], int *constraint);
int		colup_check(int cnt, int num, int map[][4], int *constraint);
#endif
