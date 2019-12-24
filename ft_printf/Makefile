# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acthulhu <acthulhu@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/08 14:43:40 by acthulhu          #+#    #+#              #
#    Updated: 2019/12/23 21:18:35 by acthulhu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all signal clean fclean re

Color_Off='\033[0m'

Black='\033[0;30m'
BRed='\033[1;31m'
BGreen='\033[3;32m'
Yellow='\033[0;33m'
Blue='\033[0;34m'
Purple='\033[0;35m'
Cyan='\033[0;36m'  
BWhite='\033[1;37m'

NAME = libftprintf.a

SOURCES_DIRECTORY = ./sources/
SOURCE_FILES = begin_func.c \
			count_print.c \
			error.c \
			find_between.c \
			flag_cleaner.c \
			float_solver.c \
			float_solver_2.c \
			handle_signed_string.c \
			handle_precision.c \
			handle_unsigned.c \
			handle_unsigned_string.c \
			ft_arithm.c \
			ft_printf.c \
			parse_flags.c \
			printers.c \
			signed_solver.c \
			string_char.c \
			some_to_a.c \
			unsigned_solver.c  

LIBFT_DIRECTORY = ./libft/
LIBFT_SOURCES = ft_btree_add.c ft_btree_search.c ft_btreenew.c \
		  ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_isspace.c \
		  ft_itoa.c ft_atoi.c \
		  ft_list_find.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c \
		  ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c ft_bzero.c \
		  ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c \
		  ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c \
		  ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c \
		  ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c \
		  ft_tolower.c ft_toupper.c \
		  get_next_line.c ft_delete_two_dimensional.c

SOURCES = $(SOURCE_FILES) $(LIBFT_SOURCES)

OBJECT_FILES = $(patsubst %.c, %.o, $(SOURCES))
OBJECTS_DIRECTORY = ./objects/
OBJECTS = $(addprefix $(OBJECTS_DIRECTORY), $(OBJECT_FILES))

HEADERS_DIRECTORY = ./includes/
HEADER_FILES = libft.h get_next_line.h ft_printf.h
HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(HEADER_FILES))

LIBFT_SOURCE = libft.a
LIBFT_DIRECTORY = ./libft/
LIBFT = $(addprefix $(LIBFT_DIRECTORY), $(LIBFT_SOURCE))

CC = gcc

FLAGS = -g #-Wall -Wextra -Werror # Не забудб про GGGGG

all: $(NAME)

$(NAME): signal $(OBJECTS)
	@ar -rcs $(NAME) $(OBJECTS)
	@printf $(BGreen)"SUCCESS!\n"$(Color_Off)

$(OBJECTS_DIRECTORY)%.o: $(SOURCES_DIRECTORY)%.c $(HEADERS)
	@mkdir -p ./objects
	@$(CC) $(FLAGS) -c $< -o $@ -I $(HEADERS_DIRECTORY)
	

$(OBJECTS_DIRECTORY)%.o: $(LIBFT_DIRECTORY)%.c $(HEADERS)
	@$(CC) $(FLAGS) -c $< -o $@ -I $(HEADERS_DIRECTORY)

signal:
	@printf $(BGreen)"Start compilling...\n"$(Color_Off)

clean:
	@/bin/rm -rf $(OBJECTS_DIRECTORY)
	@printf $(BRed)"Objects cleaned\n"

fclean: clean
	@/bin/rm -f $(NAME)
	@printf "Binaries have been cleaned\n"$(Color_Off)

re: fclean all
