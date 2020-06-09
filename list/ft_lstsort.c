/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 16:56:56 by ujyzene           #+#    #+#             */
/*   Updated: 2020/06/10 00:58:47 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_lstsort(t_list *lst, int (*cmp)(void *, void *))
{
	void	*swap;
	t_list	*tmp;
	int		rep;

	rep = 1;
	while (rep > 0)
	{
		rep = 0;
		tmp = lst;
		while (tmp && tmp->next)
		{
			if ((*cmp)(tmp->content, tmp->next->content) > 0)
			{
				swap = tmp->content;
				tmp->content = tmp->next->content;
				tmp->next->content = swap;
				rep++;
			}
			tmp = tmp->next;
		}
	}
}
