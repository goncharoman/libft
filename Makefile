# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/24 13:55:20 by ujyzene           #+#    #+#              #
#    Updated: 2019/10/24 03:41:34 by ujyzene          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## COLORS ##
RESET	= \e[0m
ITALIC	= \e[3m
RED		= \e[31m
GREEN	= \e[32m
YELLOW	= \e[33m
BLUE	= \e[34m
MAGENTA	= \e[35m

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

HEAD	= $(addprefix includes/, \
			libft.h \
			ft_structs.h \
			get_next_line.h )

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
			ft_uitoa_base.c )
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
			ft_lstiter.c \
			ft_lstlen.c \
			ft_lstmap.c \
			ft_lstnew.c \
			ft_lstsort.c )
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
			ft_readline.c \
			get_next_line.c )

# OBJ 	= $(addprefix $(TEMP)/, $(FILES):.c=.o))
OBJS	= $(FILES:%.c=$(TEMP)/%.o)

.PHONY: clean all re fclean

all : $(TEMP) $(OBJS) $(NAME)

$(NAME) : $(OBJS) $(HEAD)
	@ printf "$(CLEARL)\r"
	@ ar rcs $(NAME) $(OBJS)
	@ ranlib $(NAME)
	@ printf "Create $(NAME) $(GREEN)done!$(RESET)\n"

$(TEMP):
	@ mkdir -p $@
	@ cd $@ && mkdir -p $(DIRS)

$(TEMP)/%.o : $(SRCS)/%.c
	@ $(CC) $(FLAGS) -I $(INCL) -o $@ -c $<
	@ printf "$(YELLOW)Compile:$(RESET) %21s\r" "$(notdir $@)"

clean :
	@ rm -rf $(TEMP)
	@ printf "$(YELLOW)Objs files clear$(RESET)\n"

fclean : clean
	@ rm -rf $(NAME)
	@ printf "$(YELLOW)$(NAME) removing!$(RESET)\n"

re : fclean all
