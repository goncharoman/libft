/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsttail.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 12:45:35 by ujyzene           #+#    #+#             */
/*   Updated: 2020/04/21 12:49:09 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list	*ft_lsttail(t_list **head)
{
	t_list	*current;

	if (head)
	{
		if (*head)
		{
			current = *head;
			while (current->next)
				current = current->next;
			return (current);
		}
	}
	return (NULL);
}
