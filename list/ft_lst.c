/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 03:49:36 by ujyzene           #+#    #+#             */
/*   Updated: 2020/06/10 00:56:54 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** NOTE: использует оригинальный content
*/

t_list			*ft_lst(void const *content, size_t content_size)
{
	t_list *tmp;

	if (!(tmp = (t_list*)ft_memalloc(sizeof(t_list))))
		return (NULL);
	tmp->content = (void*)content;
	tmp->content_size = (!content ? 0 : content_size);
	tmp->next = NULL;
	return (tmp);
}
