.PHONY: lib_all lib_clean lib_flcean lib_re

Color_Off='\033[0m'

Black='\033[0;30m'
BRed='\033[1;31m'
BGreen='\033[3;32m'
Yellow='\033[0;33m'
Blue='\033[0;34m'
Purple='\033[0;35m'
Cyan='\033[0;36m'  
BWhite='\033[1;37m'

NAME = libft.a

LIBFT_SOURCES_DIRECTORY = ./libft/ft_printf_sources/
PRINTF_SOURCES = begin_func.c \
			count_print.c \
			flag_cleaner.c \
			float_solver.c \
			float_solver_2.c \
			float_rounding.c \
			f_string_solver.c \
			e_string_solver.c \
			handle_f.c \
			handle_e.c \
			handle_g.c \
			handle_signed_string.c \
			handle_precision.c \
			handle_precision.c \
			handle_unsigned.c \
			handle_unsigned_string.c \
			handle_flags.c \
			ft_arithm.c \
			ft_printf.c \
			parse_flags.c \
			printers.c \
			signed_solver.c \
			string_char.c \
			some_to_a.c \
			unsigned_solver.c \
			error.c

LIBFT_DIRECTORY = ./libft/lib_sources/
LIB_SOURCES = ft_btree_add.c ft_btree_search.c ft_btreenew.c \
		  ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_isspace.c \
		  ft_itoa.c ft_atoi.c ft_atoll.c\
		  ft_list_find.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstrev.c ft_lstmap.c ft_lstnew.c \
		  ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c ft_bzero.c \
		  ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c \
		  ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c \
		  ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c \
		  ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c \
		  ft_tolower.c ft_toupper.c \
		  get_next_line.c ft_delete_two_dimensional.c find_between.c

LIBFT_SOURCES = $(PRINTF_SOURCES) $(LIB_SOURCES)

LIBFT_OBJECT_FILES = $(patsubst %.c, %.o, $(LIBFT_SOURCES))
LIBFT_OBJECTS_DIRECTORY = ./libft/objects/
LIBFT_OBJECTS = $(addprefix $(LIBFT_OBJECTS_DIRECTORY), $(LIBFT_OBJECT_FILES))

LIBFT_HEADERS_DIRECTORY = ./libft/includes/
LIBFT_HEADER_FILES = libft.h get_next_line.h ft_printf.h
LIBFT_HEADERS = $(addprefix $(LIBFT_HEADERS_DIRECTORY), $(LIBFT_HEADER_FILES))

CC = gcc

FLAGS = -Wall -Wextra -Werror

lib_all: $(NAME)

$(NAME): $(LIBFT_OBJECTS)
	@ar -rcs $(NAME) $(LIBFT_OBJECTS)
	@printf $(BGreen)"libft.a created!\n"$(Color_Off)

$(LIBFT_OBJECTS_DIRECTORY)%.o: $(LIBFT_SOURCES_DIRECTORY)%.c $(LIBFT_HEADERS)
	@mkdir -p ./libft/objects
	@$(CC) $(FLAGS) -c $< -o $@ -I $(LIBFT_HEADERS_DIRECTORY)
	

$(LIBFT_OBJECTS_DIRECTORY)%.o: $(LIBFT_DIRECTORY)%.c $(LIBFT_HEADERS)
	@$(CC) $(FLAGS) -c $< -o $@ -I $(LIBFT_HEADERS_DIRECTORY)

lib_clean:
	@/bin/rm -rf $(LIBFT_OBJECTS_DIRECTORY)
	@printf $(BRed)"Libft's objects cleaned\n"

lib_fclean: lib_clean
	@/bin/rm -f $(NAME)
	@printf "Libft's binaries have been cleaned\n"

lib_re: lib_fclean lib_all
