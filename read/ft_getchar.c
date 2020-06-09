/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 22:55:02 by ujyzene           #+#    #+#             */
/*   Updated: 2020/06/10 01:21:28 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	ft_getchar(void)
{
	char	buff;
	size_t	ret;

	if ((ret = read(STDIN_FILENO, &buff, 1)) != 1)
		return ('\0');
	return (buff);
}
