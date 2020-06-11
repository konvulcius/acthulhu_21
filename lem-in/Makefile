NAME = lem-in
CC = clang
FLAGS = -Wall -Wextra -Werror
INCLUDES_DIR = ./include/
HEADERS_FILES = ft_data_structs.h ft_lemin.h get_next_line.h
HEADERS = $(addprefix $(INCLUDES_DIR), $(HEADERS_FILES))

SOURCE_DIR = ./srcs/

OBJECTS_DIRECTORY = objects/
LIBFT_DIR = ./libft/

SOURCE_FILES = ft_array_fillers.c \
			ft_avl_tree_init.c \
			ft_avl_tree_insert.c \
			ft_avl_tree_remove.c \
			ft_errors.c \
			ft_lemin_fill_data.c \
			ft_lemin_fill_rooms.c \
			ft_lemin_fill_data_utils.c \
			ft_utils.c \
			ft_lemin_utils_2.c \
			ft_validation.c \
			get_next_line.c \
			ft_lemin_main.c \
			ft_lemin_init.c \
			ft_lemin_print.c \
			ft_lemin_ant_move.c \
			ft_get_ways.c \
			ft_get_ways2.c \
			ft_lemin_find_way_utils.c \
			ft_split_and_delete_reverse_node.c \
			ft_save_way_in_table.c \
			ft_lemin_check_ways_count.c \
			ft_lemin_suurballe.c \
			ft_lemin_suurballe_utils.c \
			ft_lemin_print_moves.c \
			ft_lemin_print_rooms.c \
			ft_lemin_bellman_ford.c \
			ft_lemin_check_path.c \
			ft_lemin_clear_data.c

OBJ_FILES = $(patsubst %.c, %.o, $(SOURCE_FILES))
OBJ = $(addprefix $(OBJECTS_DIRECTORY), $(OBJ_FILES))

# COLORS
GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -sC $(LIBFT_DIR)
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME) -L$(LIBFT_DIR) -lft
	@echo "$(GREEN)$(NAME) created$(RESET)"

$(OBJECTS_DIRECTORY)%.o: $(SOURCE_DIR)%.c
	@mkdir -p $(OBJECTS_DIRECTORY)
	@$(CC) $(FLAGS) -c $< -o $@ -I $(INCLUDES_DIR) -I $(LIBFT_DIR)includes/
	@echo "$(GREEN).$(RESET)\c"

del_lib:
	@$(MAKE) -sC $(LIBFT_DIR) clean

clean: del_lib
	@/bin/rm -rf $(OBJECTS_DIRECTORY)
	@echo "$(NAME): $(RED)object files deleted$(RESET)"

fclean: clean
	@$(MAKE) -sC $(LIBFT_DIR) fclean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 