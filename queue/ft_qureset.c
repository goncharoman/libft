/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qureset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 01:13:08 by ujyzene           #+#    #+#             */
/*   Updated: 2019/10/24 01:15:39 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_qureset(t_queue *queue)
{
	queue->size = 0;
	queue->front = 0;
	queue->rear = queue->capacity - 1;
}
