/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 14:52:02 by ujyzene           #+#    #+#             */
/*   Updated: 2020/06/10 01:01:21 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_pf.h>

t_pfs		pfs_init(void)
{
	t_pfs	tmp;

	if (!(tmp.value = ft_strnew(PF_BUFFSIZE)))
	{
		tmp.last = 0;
		tmp.len = 0;
	}
	tmp.len = PF_BUFFSIZE;
	tmp.last = 0;
	return (tmp);
}

int			pfs_expand(t_pfs *fstr)
{
	char	*tmp;

	if (!(tmp = ft_strnew(fstr->len + PF_BUFFSIZE)))
		return (0);
	ft_strcpy(tmp, fstr->value);
	free(fstr->value);
	fstr->value = tmp;
	fstr->len += PF_BUFFSIZE;
	return (1);
}

static int	pfs_fill(t_pfs *fstr, char *buff, size_t size)
{
	if (!buff)
		return (-1);
	if (size == (size_t)-1)
		size = ft_strlen(buff);
	while (fstr->len < fstr->last + size)
		if (!pfs_expand(fstr))
			return (0);
	if (fstr->len >= fstr->last + size)
	{
		ft_strncat(fstr->value, buff, size);
		fstr->last += size;
	}
	return (1);
}

void		pfs_push(t_pfs *fstr, char *buff, size_t size)
{
	if (!(pfs_fill(fstr, buff, size)))
	{
		ft_strdel(&fstr->value);
		exit(1);
	}
}
