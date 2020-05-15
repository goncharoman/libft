/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 01:17:01 by ujyzene           #+#    #+#             */
/*   Updated: 2020/05/14 23:53:22 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_pf.h>

t_format	pf_format_init(void)
{
	t_format tmp;

	tmp = (t_format){
		.prec = -1,
		.width = 0,
		.sign = false,
		.left = false,
		.alt = false,
		.pad = 32,
		.mod = M_NONE,
		.base = 0,
	};
	return (tmp);
}
