# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acthulhu <acthulhu@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/05 15:11:12 by lliza             #+#    #+#              #
#    Updated: 2020/05/06 17:48:40 by acthulhu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SUBLIBNAME = libftprintf.a
SUBLIBPATH = ftprintf/
H_FILES = 	libft.h\
			ft_get_next_line.h \
			ft_printf.h

H_FILES_DIR = ./includes/
INCS = $(addprefix $(H_FILES_DIR), $(H_FILES))
CC = gcc
FLAGS = -g -O3 -Wall -Wextra -Werror
FILES =	ft_isdigit.c \
		ft_atoi.c \
		ft_atoi_base.c \
		ft_bzero.c \
		ft_erase_node_content.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_lstadd.c \
		ft_lstcpy.c \
		ft_lstdel.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstlen.c \
		ft_lstmap.c \
		ft_lstnew.c \
		ft_memalloc.c \
		ft_memccpy.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memdel.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar.c \
		ft_putchar_fd.c \
		ft_putendl.c \
		ft_putendl_fd.c \
		ft_putnbr.c \
		ft_putnbr_fd.c \
		ft_putstr.c \
		ft_putstr_fd.c \
		ft_strcat.c \
		ft_strchr.c \
		ft_strclr.c \
		ft_strcmp.c \
		ft_strcpy.c \
		ft_strdel.c \
		ft_strdup.c \
		ft_strequ.c \
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
		ft_strnequ.c \
		ft_strnew.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strrev.c \
		ft_strsplit.c \
		ft_strstr.c \
		ft_strsub.c \
		ft_strtrim.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_bst_create_node.c \
		ft_bst_find_node.c \
		ft_bst_insert_node.c \
		ft_sqrt.c \
		ft_num_len.c \
		ft_unsigned_num_len.c \
		ft_num_to_power.c \
		ft_strcpy_reverse.c \
		ft_get_next_line.c \
		ft_swap_nums.c

SRCS_DIR = srcs/
SRC_FILES = $(addprefix $(SRCS_DIR), $(FILES))
OBJS_DIR = objs/
OBJ_FILES = $(patsubst %.c, %.o, $(FILES))
OBJS = $(addprefix $(OBJS_DIR), $(OBJ_FILES))

# COLORS

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJS_DIR) $(OBJS)
	@$(MAKE) -C $(SUBLIBPATH) $(SUBLIBNAME)
	@cp $(SUBLIBPATH)$(SUBLIBNAME) $(NAME)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "\n$(GREEN)$(NAME) created$(RESET)"

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c 
	@$(CC) $(FLAGS) -I$(H_FILES_DIR) -c $< -o $@
	@echo "$(GREEN).$(RESET)\c"

clean_sublib:
	@$(MAKE) -sC $(SUBLIBPATH) clean

fclean_sublib:
	@$(MAKE) -sC $(SUBLIBPATH) fclean

clean: clean_sublib
	@/bin/rm -rf $(OBJS_DIR)

fclean: clean fclean_sublib
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re clean_sublib fclean_sublib
