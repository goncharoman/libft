/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_forms_handlers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 11:46:01 by ujyzene           #+#    #+#             */
/*   Updated: 2020/05/15 04:11:26 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_pf.h>

static inline short get_base(char c)
{
	if (c == 'o' || c == 'O')
		return (8);
	else if (c == 'x' || c == 'X' || c == 'p')
		return (16);
	else
		return (10);
}

char	*pf_form_handler(char **format, t_format *p, va_list args)
{
	char				ch;
	static const char	table[67] = {
		[0] = 4, [2] = 3,3,3, [12] = 2, [16] = 5, [18] = 2, [21] = 2, [32] = 4, [33] = 1, [34] = 3,3,3, [38] = 1, [43] = 2, [44] = 2, [45] = 2,
		[48] = 5, [50] = 2, [53] = 2
	};
	char				*(*handlers[7])(char, t_format*, va_list) = {
		NULL,
		pf_int_handler,
		pf_uint_handler,
		pf_float_handler,
		pf_char_handler,
		pf_string_handler,
	};

	if ((ch = *(*format)++) == '%')
		return (pf_char_handler(ch, p, args));
	p->base = get_base(ch);
	if (!handlers[(int)table[ch - 67]])
		return (NULL);
	return (handlers[(int)table[ch - 67]](ch, p, args));
}
