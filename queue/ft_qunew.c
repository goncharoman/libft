/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qunew.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 18:22:19 by ujyzene           #+#    #+#             */
/*   Updated: 2020/06/10 01:20:07 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_queue	*ft_qunew(size_t capacity)
{
	t_queue	*tmp;

	if (!(tmp = (t_queue*)malloc(sizeof(t_queue))))
		return (NULL);
	tmp->capacity = capacity;
	tmp->front = 0;
	tmp->size = 0;
	tmp->rear = capacity - 1;
	if (!(tmp->array = (int*)malloc(tmp->capacity * sizeof(int))))
	{
		free(tmp);
		return (NULL);
	}
	return (tmp);
}
