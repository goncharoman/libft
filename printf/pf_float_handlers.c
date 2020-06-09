/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_float_handlers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 00:40:28 by ujyzene           #+#    #+#             */
/*   Updated: 2020/06/10 01:14:59 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_pf.h>

static void	pf_float_fill(t_format *p, char *dst, char *value, int len)
{
	if (p->sign && p->pad == 48 && len--)
		*dst = *value++;
	ft_strcat(dst + (p->left ? 0 : p->width - len), value);
	if (p->width > len)
		ft_memset(dst + (p->sign && p->pad == 48) + (p->left ? len : 0),
			p->pad, p->width - len - (p->sign && p->pad == 48));
}

char		*pf_float_handler(char ch, t_format *p, va_list args)
{
	char	*value;
	char	*tmp;
	int		len;

	if (p->prec == -1)
		p->prec = 6;
	if (p->mod == M_LDOUBLE)
		value = ft_lftoa(va_arg(args, long double), p->prec, p->sign);
	else
		value = ft_tolower(ch) != 'e' ?
			ft_ftoa(va_arg(args, double), p->prec, p->sign) :
			ft_ftoe(va_arg(args, double), p->prec, p->sign);
	if ((len = ft_strlen(value)) && p->width < len)
		p->width = len;
	if (!(tmp = ft_strnew(p->width)))
		return (NULL);
	p->sign = PF_SIGN(*value);
	pf_float_fill(p, tmp, value, len);
	if (ft_strchr("Ee", ch))
		ft_chcase(&tmp, &ft_tolower);
	ft_strdel(&value);
	return (tmp);
}
