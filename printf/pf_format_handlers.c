/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_format_handlers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 11:41:58 by ujyzene           #+#    #+#             */
/*   Updated: 2020/06/10 01:02:33 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_pf.h>

inline void			pf_flag_handler(char ch, t_format *p)
{
	if (ch == '+')
		p->sign = true;
	else if (ch == '-')
		p->left = true;
	else if (ch == ' ' && !p->left)
		p->pad = 32;
	else if (ch == '#')
		p->alt = true;
	else if (ch == '0' && !p->left)
	{
		if (p->pad == 32)
			p->left = 0;
		p->pad = 48;
	}
}

inline void			pf_mod_handler(char ch, t_format *p)
{
	if (ch == 'l')
		p->mod = M_LONG;
	else if (ch == 'h')
		p->mod = M_HALF;
	else if (ch == 'L' || ch == 'q')
		p->mod = M_LDOUBLE;
	else if (ch == 'z' || ch == 'Z')
		p->mod = M_SIZET;
	else if (ch == 'j')
		p->mod = M_MAXT;
}

static unsigned int	n_from_format(char **format)
{
	int		n;
	char	*num;

	n = 0;
	while (**format && ft_isdigit(*(*format + n)))
		n++;
	num = ft_strsub(*format, 0, n);
	*format += n;
	n = ft_atoi(num);
	free(num);
	return (n);
}

inline void			pf_width_handler(char **format, t_format *p, va_list args)
{
	if (**format == '*')
	{
		p->width = va_arg(args, int);
		(*format)++;
	}
	else
		p->width = n_from_format(format);
}

inline void			pf_prec_handler(char **format, t_format *p, va_list args)
{
	(*format)++;
	if (**format == '*')
	{
		p->prec = va_arg(args, int);
		(*format)++;
	}
	else
		p->prec = n_from_format(format);
}
