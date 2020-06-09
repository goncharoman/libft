/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 14:40:12 by ujyzene           #+#    #+#             */
/*   Updated: 2020/06/10 00:59:35 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int	ft_printf(const char *format, ...)
{
	int		err;
	va_list	args;

	va_start(args, format);
	err = ft_vprintf(1, (char*)format, args);
	va_end(args);
	return (err);
}

int	ft_fprintf(int fd, const char *format, ...)
{
	int		err;
	va_list	args;

	va_start(args, format);
	err = ft_vprintf(fd, (char*)format, args);
	va_end(args);
	return (err);
}
