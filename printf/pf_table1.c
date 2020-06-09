/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_table1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 11:36:02 by ujyzene           #+#    #+#             */
/*   Updated: 2020/06/10 01:18:03 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_pf.h>

/*
** начало парсинга флагов.
** обработка следующего символа за символом % (флаг и/или ширина)
** таблица дла [флаг][ширина][точность][модификатор][тип]
*/

inline char	pf_table0(char index)
{
	const char	table0[30] = {
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
		20, 21, 22, 23, 24, 25, 26, 27, 28, 29
	};

	return (table0[(int)index]);
}

/*
** парсинг после ширины
** таблица дла [точность][модификатор][тип]
*/

inline char	pf_table1(char index)
{
	const char	table1[30] = {
		0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
		20, 21, 22, 23, 24, 25, 26, 27, 28, 29
	};

	return (table1[(int)index]);
}

/*
** парсинг после точности
** таблица дла [модификатор][тип]
*/

inline char	pf_table2(char index)
{
	const char	table2[30] = {
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
		20, 21, 22, 23, 24, 25, 26, 27, 28, 29
	};

	return (table2[(int)index]);
}

/*
** парсинг после модификатора
** таблица дла [тип]
*/

inline char	pf_table4(char index)
{
	const char	table4[30] = {
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 14, 15, 16, 17, 18, 19, 20,
		21, 22, 23, 24, 25, 26, 0, 0, 0
	};

	return (table4[(int)index]);
}
