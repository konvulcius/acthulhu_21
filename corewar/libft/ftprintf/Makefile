NAME = libftprintf.a
HPATH = includes/
CC = gcc
IFLAGS = -I $(HPATH) -I ../includes
FLAGS = -g -O3 -Wall -Wextra -Werror $(IFLAGS)
SRCS =	ft_printf.c \
		ft_is_flag.c \
		ft_is_length.c \
		ft_handle_specs.c \
		ft_data_preprocessing.c \
		ft_data_processing.c \
		ft_calculate_width.c \
		ft_calculate_width_unsigned.c \
		ft_calculate_precision.c \
		ft_add_figures_to_buff.c \
		ft_add_figures_to_buff_unsigned.c \
		ft_add_num_to_buff.c \
		ft_add_u_num_to_buff.c \
		ft_add_hex_to_buff.c \
		ft_add_string_to_buff.c \
		ft_add_width_to_data.c \
		ft_add_width_to_buff.c \
		ft_add_flag.c \
		ft_add_length.c \
		ft_add_char_to_buff.c \
		ft_add_precision_to_data.c \
		ft_add_int_precision.c \
		ft_show_ldbl_bits.c \
		ft_get_exponent.c \
		ft_get_int_part.c \
		ft_add_figure_to_buff.c \
		ft_multiply_buff_by_two.c \
		ft_fill_buff_for_one_two.c \
		ft_add_buff_to_buff.c \
		ft_union_ldbl_bitmove_right.c \
		ft_convert_ldbl_to_fraction.c \
		ft_round_ldbl_up.c \
		ft_handle_double.c \
		ft_ldbl_add_int_part_to_buff.c \
		ft_ldbl_add_precision_to_buff.c \
		ft_ldbl_one_buff_to_rule_them_all.c \
		ft_color.c \
		ft_handle_strings_array.c \
		ft_handle_size_t.c

OBJS = $(SRCS:%.c=%.o)

# COLORS

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@
	@echo "$(GREEN).$(RESET)\c"

clean:
	@/bin/rm -f $(OBJS)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
