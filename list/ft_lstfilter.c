/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfilter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 21:00:48 by ujyzene           #+#    #+#             */
/*   Updated: 2020/05/16 21:30:40 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_lstfilter(t_list	**alst, t_bool (*cmp)(void *), void (*del)(void *))
{
	t_list *tmp;

	if ((tmp = *alst))
		return ;
	if (cmp(tmp->content))
	{
		del(tmp->content);
		*alst = tmp->next;
		free(tmp);
	}
	else
		ft_lstfilter(&(tmp->next), cmp, del);
}
