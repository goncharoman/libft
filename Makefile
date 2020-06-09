# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/24 13:55:20 by ujyzene           #+#    #+#              #
#    Updated: 2020/06/10 01:23:10 by ujyzene          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## COLORS ##
F_DIM	= \033[2m
F_BOLD	= \033[1m
GRAY	= \033[38;5;253m
RESET	= \e[0m
ITALIC	= \e[3m
RED		= \033[38;5;160m
GREEN	= \033[38;5;35m
YELLOW	= \033[38;5;184m
BLUE	= \033[38;5;32m

## ESC ##
CLEARL	= \e[2K
CLEARS	= \e[2J
CLEARUP	= \e[1J

## GENERAL ##
CC		= gcc
FLAGS	= -Wall -Wextra -Werror
NAME	= libft.a

## FILES ##
SRCS	= .
INCL	= includes
TEMP 	= temp
DIRS	= str \
			mem \
			list \
			math \
			put \
			queue \
			read \
			stack \
			printf

HEAD	= $(addprefix includes/, \
			libft.h \
			ft_structs.h \
			get_next_line.h \
			ft_printf.h \
			ft_pf.h \
			)

	# str #
FILES	= $(addprefix str/, \
			ft_atoi.c \
			ft_atoi_base.c \
			ft_chcase.c \
			ft_ftoa.c \
			ft_ftoe.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_islower.c \
			ft_isprint.c \
			ft_isspace.c \
			ft_isupper.c \
			ft_itoa.c \
			ft_itoa_base.c \
			ft_lftoa.c \
			ft_strarrdel.c \
			ft_strarrlen.c \
			ft_strcat.c \
			ft_strchr.c \
			ft_strclr.c \
			ft_strcmp.c \
			ft_strcpy.c \
			ft_strdel.c \
			ft_strdup.c \
			ft_stremove.c \
			ft_strequ.c \
			ft_strindexof.c \
			ft_striter.c \
			ft_striteri.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlen.c \
			ft_strmap.c \
			ft_strmapi.c \
			ft_strncat.c \
			ft_strncmp.c \
			ft_strncpy.c \
			ft_strndup.c \
			ft_strnequ.c \
			ft_strnew.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strrev.c \
			ft_strsepjoin.c \
			ft_strsplit.c \
			ft_strstr.c \
			ft_strsub.c \
			ft_strtrim.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_uitoa_base.c \
			)
	# mem #
FILES	+= $(addprefix mem/, \
			ft_bzero.c \
			ft_memalloc.c \
			ft_memccpy.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memdel.c \
			ft_memmove.c \
			ft_memset.c )
	# put #
FILES	+= $(addprefix put/, \
			ft_putchar.c \
			ft_putchar_fd.c \
			ft_putendl.c \
			ft_putendl_fd.c \
			ft_putnbr.c \
			ft_putnbr_fd.c \
			ft_putstr.c \
			ft_putstr_fd.c )
	# list #
FILES	+= $(addprefix list/, \
			ft_lst.c \
			ft_lstadd.c \
			ft_lstappend.c \
			ft_lstdel.c \
			ft_lstdelone.c \
			ft_lstriter.c \
			ft_lstiter.c \
			ft_lstlen.c \
			ft_lstmap.c \
			ft_lstfilter.c \
			ft_lstnew.c \
			ft_lstsort.c \
			ft_lsttail.c \
			)
	# stack #
FILES	+= $(addprefix stack/, \
			ft_stnew.c \
			ft_stpop.c \
			ft_stpush.c )
	# math #
FILES 	+= $(addprefix math/, \
			ft_abs.c \
			ft_pow.c )
	# queue #
FILES	+= $(addprefix queue/, \
			ft_dequeue.c \
			ft_enqueue.c \
			ft_qunew.c \
			ft_quremove.c \
			ft_qureset.c )
	# read #
FILES 	+= $(addprefix read/, \
			ft_getchar.c \
			ft_readline.c \
			get_next_line.c )

	# ft_printf #
FILES	+= $(addprefix printf/, \
			ft_pf.c \
			ft_printf.c \
			ft_vprintf.c \
			pf_chars_handler.c \
			pf_float_handlers.c \
			pf_format.c \
			pf_format_handlers.c \
			pf_forms_handlers.c \
			pf_int_handler.c \
			pf_str.c \
			pf_table1.c \
			pf_table2.c \
			pf_tables_handlers.c \
			)

# OBJ 	= $(addprefix $(TEMP)/, $(FILES):.c=.o))
OBJS	= $(FILES:%.c=$(TEMP)/%.o)

.PHONY: clean all re fclean

all : $(TEMP) $(OBJS) $(NAME)

$(NAME) : $(OBJS) $(HEAD)
	@ printf "$(CLEARL)\r"
	@ ar rcs $(NAME) $(OBJS)
	@ ranlib $(NAME)
	@ printf "$(F_DIM)$(F_BOLD)$(GRAY)%-10s$(RESET) $(F_BOLD)$(NAME)$(RESET) $(GREEN)were created!$(RESET)\n" "(lib)"

$(TEMP):
	@ mkdir -p $@
	@ cd $@ && mkdir -p $(DIRS)

$(TEMP)/%.o : $(SRCS)/%.c
	@ $(CC) $(FLAGS) -I $(INCL) -o $@ -c $<
	@ printf "$(F_DIM)$(F_BOLD)$(GRAY)%-10s$(RESET) $(YELLOW)compile:$(RESET) %21s\r" "(lib)" "$(notdir $@)"

clean :
	@ rm -rf $(TEMP)
	@ printf "$(F_DIM)$(F_BOLD)$(GRAY)%-10s$(RESET) $(YELLOW)temp files were deleted$(RESET)\n" "(lib)"

fclean : clean
	@ rm -rf $(NAME)
	@ printf "$(F_DIM)$(F_BOLD)$(GRAY)%-10s$(RESET) $(F_BOLD)$(NAME)$(RESET) $(YELLOW)were deleted$(RESET)\n" "(lib)"

re : fclean all
