/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_chars_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 00:43:47 by ujyzene           #+#    #+#             */
/*   Updated: 2020/06/10 01:00:42 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_pf.h>

char	*pf_char_handler(char ch, t_format *p, va_list args)
{
	char	*c;

	p->pad = 32;
	if (p->width < 1)
		p->width = 1;
	if (!(c = ft_strnew(p->width)))
		return (NULL);
	if ((ch == '%' || (ch = va_arg(args, int))) && p->prec != 0)
		c[p->left ? 0 : p->width - 1] = ch;
	if (p->width > 1)
		ft_memset(c + (p->left ? 1 : 0), p->pad, p->width - 1);
	return (c);
}

char	*pf_string_handler(char ch, t_format *p, va_list args)
{
	char	*tmp;
	char	*value;
	int		len;

	p->pad = 32;
	if (!(value = va_arg(args, char*)))
		value = "(null)";
	if ((len = ft_strlen(value)) && p->width < len)
		p->width = len;
	if (ch != 's' || !(tmp = ft_strnew(p->width)))
		return (NULL);
	ft_strcat(tmp + (p->left ? 0 : p->width - len), value);
	if (p->width > len)
		ft_memset(tmp + (p->left ? len : 0), p->pad, p->width - len);
	return (tmp);
}
