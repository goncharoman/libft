/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_tables_handlers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 01:40:18 by ujyzene           #+#    #+#             */
/*   Updated: 2020/05/15 04:12:49 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_pf.h>

inline char	pf_table1_handler(char **format, t_format *p, va_list args)
{
	pf_width_handler(format, p, args);
	return (pf_next_table(table1, **format));
}

inline char	pf_table2_handler(char **format, t_format *p, va_list args)
{
	if (**format == '%')
		return (table4);
	pf_prec_handler(format, p, args);
	return (pf_next_table(table2, **format));
}

inline char	pf_table3a_handler(char **format, t_format *p)
{
	char	responce;

	if ((responce = pf_next_table(table3a, *(*format + 1))) == table3a)
	{
		*format += 2;
		p->mod = M_HHALF;
		responce = pf_next_table(table3a, **format);
	}
	else
		pf_mod_handler(*(*format)++, p);
	return (responce);
}

inline char	pf_table3b_handler(char **format, t_format *p)
{
	char	responce;

	if ((responce = pf_next_table(table3b, *(*format + 1))) == table3b)
	{
		*format += 2;
		p->mod = M_LLONG;
		responce = pf_next_table(table3b, **format);
	}
	else
		pf_mod_handler(*(*format)++, p);
	return (responce);
}
