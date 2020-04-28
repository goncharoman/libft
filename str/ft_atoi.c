/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 15:08:48 by ujyzene           #+#    #+#             */
/*   Updated: 2020/04/29 00:26:00 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int32_t	ft_atoi32(const char *str)
{
	uint64_t	result;
	uint64_t	border;
	int8_t		sign;

	result = 0;
	border = (uint64_t)(INT64_MAX / 10);
	while (ft_isspace(*str))
		str++;
	sign = (*str == '-') ? -1 : 1;
	while (ft_isdigit(*str))
	{
		if ((result > border || (result == border && *str - '0' > 7)) &&
			sign == 1)
			return (-1);
		else if ((result > border || (result == border && *str - '0' > 8)) &&
			sign == -1)
			return (0);
		result = result * 10 + (*str++ - '0');
	}
	return ((int32_t)(sign * result));
}

int		ft_atoi(const char *str)
{
	return ((int)ft_atoi32(str));
}
