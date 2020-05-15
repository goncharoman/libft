/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 21:08:35 by ujyzene           #+#    #+#             */
/*   Updated: 2020/05/15 04:22:26 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_pf.h>

inline t_tabcode	pf_next_table(t_tabcode table, char c)
{
	static char (*handlers[7])(char) = {
		NULL,
		&pf_table0,
		&pf_table1,
		&pf_table2,
		&pf_table3a,
		&pf_table3b,
		&pf_table4,
	};
	return (pf_pf_next_table(handlers[table](pf_jump_table(c))));
}

inline char					pf_jump_table(char ch)
{
	static const char	table[] = {
		1, 0, 0, 4, 0, 14, 0, 6, 0, 0, 7, 2, 0, 3, 9, 0, 5, 8,
		8, 8, 8, 8, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 26, 0, 25,
		0, 19, 19, 19, 0, 0, 0, 0, 12, 0, 0, 17, 0, 0, 0, 21, 0, 17,
		0, 0, 18, 0, 13, 0, 0, 0, 0, 0, 0, 26, 0, 20, 15, 19, 19, 19,
		10, 15, 28, 0, 11, 24, 23, 17, 22, 12, 0, 21, 27, 16, 0, 0, 18, 0, 13
	};
	if (ch < ' ' || ch > 'z')
		return (0);
	return (table[ch - ' ']);
}

inline t_tabcode	pf_pf_next_table(char resp)
{
	static const char	table[27] = {
		0, 1, 1, 1, 1, 1, 1, 2, 2, 3, 4, 5, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
		6, 6, 6,
	};

	return ((t_tabcode)table[(int)resp]);
}

char				*pf_parse_format(char **format, va_list args)
{
	t_tabcode	responce;
	t_format	p;

	p = pf_format_init();
	while ((responce = pf_next_table(table0, **format)) == table0)
		pf_flag_handler(*(*format)++, &p);
	if (responce == table1)
		responce = pf_table1_handler(format, &p, args);
	if (responce == table2)
		responce = pf_table2_handler(format, &p, args);
	if (responce == table3a)
		responce = pf_table3a_handler(format, &p);
	if (responce == table3b)
		responce = pf_table3b_handler(format, &p);
	if (responce == table4)
		return (pf_form_handler(format, &p, args));
	return (NULL);
}
