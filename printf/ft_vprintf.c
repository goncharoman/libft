/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 02:45:01 by ujyzene           #+#    #+#             */
/*   Updated: 2020/06/10 00:59:58 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static inline void	push_chunk(t_pfs *fstr, const char **fmt, uint32_t *offset)
{
	pfs_push(fstr, (char*)*fmt, *offset);
	*fmt += *offset;
	*offset = 0;
}

static inline void	push_spec(t_pfs *fstr, char *buff)
{
	pfs_push(fstr, buff, -1);
	if (buff)
		free(buff);
}

int					ft_vprintf(int fd, const char *format, va_list args)
{
	t_pfs		fstr;
	char		*tmp;
	uint32_t	offset;

	fstr = pfs_init();
	offset = 0;
	while (*(format + offset))
	{
		if (*(format + offset) == '%')
		{
			if (offset > 0)
				push_chunk(&fstr, &format, &offset);
			if (!*++format)
				break ;
			push_spec(&fstr, (tmp = pf_parse_format((char**)&format, args)));
		}
		else
			offset++;
	}
	pfs_push(&fstr, (char *)format, offset);
	write(fd, fstr.value, fstr.last);
	free(fstr.value);
	return (fstr.last);
}
