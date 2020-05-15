/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_int_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 12:46:28 by ujyzene           #+#    #+#             */
/*   Updated: 2020/05/15 03:19:10 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_pf.h>

inline static void	pre_form(t_format *p, char ch)
{
	if (ch == 'U' || ch == 'p')
		p->mod = M_LLONG;
	if (ch == 'p')
		p->alt = true;
}

inline static intmax_t get_int_value(t_format *p, va_list args)
{
	if (p->mod == M_NONE)
		return (va_arg(args, int));
	if (p->mod == M_LONG)
		return (va_arg(args, long));
	if (p->mod == M_LLONG)
		return (va_arg(args, long long));
	if (p->mod == M_HALF)
		return ((short)va_arg(args, int));
	if (p->mod == M_HHALF)
		return ((char)va_arg(args, int));
	if (p->mod == M_SIZET)
		return (va_arg(args, size_t));
	if (p->mod == M_MAXT)
		return (va_arg(args, intmax_t));
	else
		return (0);
}

inline static intmax_t get_uint_value(t_format *p, va_list args)
{
	if (p->mod == M_NONE)
		return (va_arg(args, unsigned int));
	if (p->mod == M_LONG)
		return (va_arg(args, unsigned long));
	if (p->mod == M_LLONG)
		return (va_arg(args, unsigned long long));
	if (p->mod == M_HALF)
		return ((unsigned short)va_arg(args, unsigned int));
	if (p->mod == M_HHALF)
		return ((unsigned char)va_arg(args, unsigned int));
	if (p->mod == M_SIZET)
		return (va_arg(args, size_t));
	if (p->mod == M_MAXT)
		return (va_arg(args, uintmax_t));
	else
		return (0);
}

char	*pf_int_handler(char ch, t_format *p, va_list args)
{
	char	*value;
	char	*tmp;
	int		len;

	ch = (ch == 'i') ? 'd' : ch;
	value = ft_itoa_base(get_int_value(p, args), p->base, p->sign);
	p->sign = PF_SIGN(*value);
	if ((len = ft_strlen(value)) && p->width < len)
		p->width = len;
	if (!(tmp = ft_strnew(p->width)))
		return (NULL);
	if (p->sign && p->pad == 48 && len--)
		*tmp = *value++;
	ft_strcat(tmp + (p->left ? 0: p->width - len), value);
	if (p->width > len)
		ft_memset(tmp + (p->sign && p->pad == 48) + (p->left ? len : 0),
			p->pad, p->width - len - (p->sign && p->pad == 48));
	ft_strdel(&value);
	return (tmp);
}

char *pf_uint_handler(char ch, t_format *p, va_list args)
{
	char		*value;
	char		*tmp;
	int			len;
	const char	*add[3] = {"", "0", "0X"};

	pre_form(p, ch);
	value = ft_uitoa_base(get_uint_value(p, args), p->base);
	if ((len = ft_strlen(value)) && p->width < len + PF_PREFIX(p))
		p->width = len + PF_PREFIX(p);
	if (!(tmp = ft_strnew(p->width)))
		return (NULL);
	if (p->alt)
		ft_strcat(tmp + (p->pad != 48 && !p->left ?
			p->width - len - PF_PREFIX(p) : 0), add[PF_PREFIX(p)]);
	ft_strcat(tmp + (p->left ? PF_PREFIX(p) : p->width - len), value);
	if (p->width > len - PF_PREFIX(p))
		ft_memset(tmp + (p->pad == 48 ? PF_PREFIX(p) : 0) + \
			(p->left ? len + PF_PREFIX(p) : 0),
			p->pad, p->width - len - PF_PREFIX(p));
	if (ft_strchr("XxOop", ch) && ft_islower(ch))
		ft_chcase(&tmp, &ft_tolower);
	ft_strdel(&value);
	return (tmp);
}
