/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_structs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 03:34:21 by ujyzene           #+#    #+#             */
/*   Updated: 2020/04/17 12:42:59 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRUCTS_H
# define FT_STRUCTS_H
# include <stdlib.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_stack
{
	int				top;
	size_t			size;
	int				*array;
}					t_stack;

typedef struct		s_queue
{
    int				front;
	int				rear;
	int				size;
    size_t			capacity;
    int				*array;
}					t_queue;

typedef union
{
	double			n;
	struct
	{
		uintmax_t	mnts : 52;
		uint32_t	exp : 11;
		uint32_t	sign : 1;
	}				spec;
}					t_float_cast;

typedef union		u_double
{
	long double		n;
	struct
	{
		uintmax_t	mnts : 64;
		uint32_t	exp : 15;
		uint32_t	sign : 1;
	}				spec;
}					t_double_cast;

typedef enum		s_bool
{
	false,
	true
}					t_bool;

#endif
