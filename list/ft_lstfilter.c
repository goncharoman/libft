/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfilter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 21:00:48 by ujyzene           #+#    #+#             */
/*   Updated: 2020/06/10 00:58:07 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_lstfilter(t_list **alst, t_bool (*cmp)(void *), void (*del)(void *))
{
	t_list	*tmp;

	if (!(tmp = *alst))
		return ;
	if (cmp(tmp->content))
	{
		del(tmp->content);
		*alst = tmp->next;
		free(tmp);
		ft_lstfilter(alst, cmp, del);
	}
	else
		ft_lstfilter(&(tmp->next), cmp, del);
}
