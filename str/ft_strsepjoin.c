/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsepjoin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 01:23:58 by ujyzene           #+#    #+#             */
/*   Updated: 2020/06/10 01:21:55 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strsepjoin(char const *s1, char const *s2, char sep)
{
	char *tmp;

	if (!s1 || !s2)
		return (NULL);
	if (!(tmp = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	ft_strcpy(tmp, s1);
	ft_strncat(tmp, &sep, 1);
	ft_strcat(tmp, s2);
	return (tmp);
}
