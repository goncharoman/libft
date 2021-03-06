/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 01:24:44 by ujyzene           #+#    #+#             */
/*   Updated: 2019/08/11 23:20:55 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

long	ft_pow(long x, unsigned int n)
{
	int res;

	res = 1;
	if (!n)
		return (1);
	while (n-- > 1)
		res *= x;
	return (res);
}
