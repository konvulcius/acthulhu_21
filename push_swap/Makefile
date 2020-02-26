.PHONY: all clean fclean re

NAME1 = push_swap
NAME2 = checker

LIBFT_MAKE = Makelib.mk
LIBFT = libft.a

SOURCES_DIRECTORY = ./sources/
SOURCE_FILES = errors.c \
		insert_instruction.c \
		reader.c \
		procedure.c \
		validation.c \
		stack_checker.c \
		algorithm.c \
		algorithm2.c \
		algorithm3.c \
		simple_solver.c \
		ft_lstiter_int.c
VISUAL_SRC = parse_attribute.c \
		visual.c \
		visual2.c \
		visual3.c \
		visual_interface.c

PUSH_SWAP = push_swap.c $(SOURCE_FILES)
CHECKER = ps_checker.c $(SOURCE_FILES) $(VISUAL_SRC)


OBJECTS_DIRECTORY = ./objects/

PUSH_SWAP_FILES = $(patsubst %.c, %.o, $(PUSH_SWAP))
PUSH_SWAP_OBJECTS = $(addprefix $(OBJECTS_DIRECTORY), $(PUSH_SWAP_FILES))

CHECKER_FILES = $(patsubst %.c, %.o, $(CHECKER))
CHECKER_OBJECTS = $(addprefix $(OBJECTS_DIRECTORY), $(CHECKER_FILES))



LIBFT_HEADERS_DIRECTORY = ./libft/includes/
LIBFT_HEADER_FILES = libft.h get_next_line.h ft_printf.h
LIBFT_HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(HEADER_FILES))



HEADERS_DIRECTORY = ./includes/
HEADER_FILES = push_swap.h visual.h
HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(HEADER_FILES))

CC = gcc

FLAGS = -Wall -Wextra -Werror

all: $(NAME1) $(NAME2)

include $(LIBFT_MAKE)

$(NAME1): $(PUSH_SWAP_OBJECTS) $(LIBFT)
	@$(CC) $(FLAGS) $^ $(LIBFT) -o $(NAME1)
	@printf $(BGreen)"push_swap CREATED\n"$(Color_Off)

$(NAME2): $(CHECKER_OBJECTS) $(LIBFT)
	@$(CC) $(FLAGS) $^ $(LIBFT) -o $(NAME2) -lmlx -framework OpenGL -framework Appkit
	@printf $(BGreen)"checker CREATED\n"$(Color_Off)

$(OBJECTS_DIRECTORY)%.o: $(SOURCES_DIRECTORY)%.c $(HEADERS) $(LIBFT_HEADERS)
	@mkdir -p ./objects
	@$(CC) $(FLAGS) -c $< -o $@ -I $(HEADERS_DIRECTORY) -I $(LIBFT_HEADERS_DIRECTORY)

clean:
	@/bin/rm -rf $(OBJECTS_DIRECTORY)
	@printf $(BRed)"Objects cleaned\n"

fclean: clean
	@/bin/rm -f $(NAME1) $(NAME2)
	@make lib_fclean
	@printf "Binaries have been cleaned\n"$(Color_Off)

re: fclean all
