.PHONY: all clean fclean re

NAME1 = push_swap
NAME2 = checker

LIBFT_MAKE = Makelib.mk
LIBFT = libft.a

SOURCES_DIRECTORY = ./sources/
SOURCE_FILES = errors.c \
		reader.c \
		procedure.c \
		validation.c \
		stack_checker.c \
		algorithm.c \
		algorithm2.c \

PUSH_SWAP = push_swap.c $(SOURCE_FILES)
CHECKER = ps_checker.c $(SOURCE_FILES)



OBJECTS_DIRECTORY = ./objects/

PUSH_SWAP_FILES = $(patsubst %.c, %.o, $(PUSH_SWAP))
PUSH_SWAP_OBJECTS = $(addprefix $(OBJECTS_DIRECTORY), $(PUSH_SWAP_FILES))

CHECKER_FILES = $(patsubst %.c, %.o, $(CHECKER))
CHECKER_OBJECTS = $(addprefix $(OBJECTS_DIRECTORY), $(CHECKER_FILES))



LIBFT_HEADERS_DIRECTORY = ./libft/includes/
LIBFT_HEADER_FILES = libft.h get_next_line.h ft_printf.h
LIBFT_HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(HEADER_FILES))



HEADERS_DIRECTORY = ./includes/
HEADER_FILES = push_swap.h
HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(HEADER_FILES))

CC = gcc

FLAGS = -g -Wall -Wextra -Werror #убрать Г

all: $(NAME1) $(NAME2)

include $(LIBFT_MAKE)

$(NAME1): $(PUSH_SWAP_OBJECTS) $(LIBFT)
	@$(CC) $(FLAGS) $^ $(LIBFT) -o $(NAME1)
	@printf $(BGreen)"push_swap CREATED\n"$(Color_Off)

$(NAME2): $(CHECKER_OBJECTS) $(LIBFT)
	@$(CC) $(FLAGS) $^ $(LIBFT) -o $(NAME2)
	@printf $(BGreen)"checker CREATED\n"$(Color_Off)

$(OBJECTS_DIRECTORY)%.o: $(SOURCES_DIRECTORY)%.c $(HEADERS) $(LIBFT_HEADERS)
	@mkdir -p ./objects
	@$(CC) $(FLAGS) -c $< -o $@ -I $(HEADERS_DIRECTORY) -I $(LIBFT_HEADERS_DIRECTORY)

clean:
	@/bin/rm -rf $(OBJECTS_DIRECTORY)
	@printf $(BRed)"Objects cleaned\n"

fclean: clean
	@/bin/rm -f $(NAME1) $(NAME2)
	@printf "Binaries have been cleaned\n"$(Color_Off)

re: fclean all