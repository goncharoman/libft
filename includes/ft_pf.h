/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 21:54:10 by ujyzene           #+#    #+#             */
/*   Updated: 2020/05/15 04:22:45 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PF_H
# define FT_PF_H
# include <stdarg.h>
# include <stdlib.h>
# include <libft.h>

# define PF_BUFFSIZE	32
# define PF_SIGN(ch)	(t_bool)(ch == 43 || ch == 45)
# define PF_PREFIX(p)	(int)(p->alt * (p->base == 16 ? 2 : p->base == 8))

typedef struct		s_pfs
{
	char	*value;
	size_t	last;
	size_t	len;
}					t_pfs;

typedef enum		e_pfmod
{
	M_NONE,
	M_LONG,
	M_LLONG,
	M_HALF,
	M_HHALF,
	M_LDOUBLE,
	M_SIZET,
	M_MAXT,
}					t_mod;

typedef struct		s_format
{
	int		prec;
	int		width;
	t_mod	mod;
	t_bool	alt;
	char	pad;
	t_bool	left;
	t_bool	sign;
	uint8_t	base;
}					t_format;

/*
** tabcodes
*/

typedef enum		e_tabcode
{
	tab_error,
	table0,
	table1,
	table2,
	table3a,
	table3b,
	table4,
}					t_tabcode;

t_pfs				pfs_init(void);
int					pfs_expand(t_pfs *fstr);
void				pfs_push(t_pfs *fstr, char *buff, size_t size);

/*
** main functions
*/

char				*pf_parse_format(char **format, va_list args);
t_format			pf_format_init(void);
extern t_tabcode	pf_next_table(t_tabcode table, char c);
extern char			pf_jump_table(char ch);
extern t_tabcode	pf_pf_next_table(char resp);
extern char 		pf_table0(char index);
extern char 		pf_table1(char index);
extern char 		pf_table2(char index);
extern char 		pf_table3a(char index);
extern char 		pf_table3b(char index);
extern char 		pf_table4(char index);
extern char			pf_table1_handler(char **format, t_format *p, va_list args);
extern char			pf_table2_handler(char **format, t_format *p, va_list args);
extern char			pf_table3a_handler(char **format, t_format *p);
extern char			pf_table3b_handler(char **format, t_format *p);
extern char			*pf_form_handler(char **format, t_format *p, va_list args);
extern void			pf_flag_handler(char ch, t_format *p);
extern void			pf_mod_handler(char ch, t_format *p);
extern void			pf_width_handler(char **format, t_format *p, va_list args);
extern void			pf_prec_handler(char **format, t_format *p, va_list args);
char 				*pf_char_handler(char ch, t_format *p, va_list args);
char 				*pf_string_handler(char ch, t_format *p, va_list args);
char 				*pf_int_handler(char ch, t_format *p, va_list args);
char 				*pf_uint_handler(char ch, t_format *p, va_list args);
char 				*pf_float_handler(char ch, t_format *p, va_list args);
#endif
