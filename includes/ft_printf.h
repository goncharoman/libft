/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 14:32:52 by ujyzene           #+#    #+#             */
/*   Updated: 2020/05/15 04:09:27 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <libft.h>
# include <ft_pf.h>

int	ft_vprintf(int fd, const char *format, va_list args);
int ft_printf(const char *format, ...);
int	ft_fprintf(int fd, const char *format, ...);
#endif
