/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstextract.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 17:33:30 by ujyzene           #+#    #+#             */
/*   Updated: 2020/05/07 17:47:28 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/* Достаем content из элемента списка и удалем этот элемент из списка */
void	*ft_lstextract(t_list **begin, int (*cmp) (void*))
{
	t_list	*next;
	void	*content;

	if (!begin || !*begin || !cmp)
		return (NULL);
	if (cmp((*begin)->content) > 0)
	{
		content = (*begin)->content;
		next = (*begin)->next;
		free(*begin);
		*begin = next;
		return (content);
	}
	else
		return (ft_lstextract(&((*begin)->next), cmp));
}
