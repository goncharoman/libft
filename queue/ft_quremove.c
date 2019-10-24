/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quremove.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 18:54:51 by ujyzene           #+#    #+#             */
/*   Updated: 2019/10/24 15:56:27 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_quremove(t_queue **queue)
{
	if (!(*queue))
		return ;
	free((*queue)->array);
	free(*queue);
	*queue = NULL;
}
