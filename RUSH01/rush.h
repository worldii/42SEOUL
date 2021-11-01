/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghapa <bbc2788@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 14:12:33 by jonghapa          #+#    #+#             */
/*   Updated: 2021/10/17 22:23:07 by minjekan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef RUSH_H
# define RUSH_H
# include "header.h"
int		recur_map_col_check(int cnt, int num, int map[][4], int *constraints);
int		recur_map_row_check(int cnt, int num, int map[][4], int *constraints);
int		recur_map(int cnt, int map[][4], int *constraints);
int		rowcol_check(int cnt, int num, int map[][4]);
int		rowleft_check(int cnt, int num, int map[][4], int *constraint);
int		rowright_check(int cnt, int num, int map[][4], int *constraint);
int		coldown_check(int cnt, int num, int map[][4], int *constraint);
int		colup_check(int cnt, int num, int map[][4], int *constraint);
void	print_map(int map[][4]);
#endif
