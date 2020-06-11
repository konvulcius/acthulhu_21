.PHONY: all clean clean_lib fclean_lib fclean re

#PATHS
SRC_PATH = ./srcs/
VM_PATH = $(SRC_PATH)vm/
VS_PATH = $(SRC_PATH)vs/
ASM_PATH = $(SRC_PATH)asm/
DISASM_PATH = $(SRC_PATH)disasm/

#MAKEFILES
VM_MK = $(VM_PATH)virtual_machine_source.mk
VS_MK = $(VS_PATH)visual_source.mk
ASM_MK = $(ASM_PATH)asm_source.mk
DISASM_MK = $(DISASM_PATH)disasm_source.mk

include  $(VM_MK) $(VS_MK) $(ASM_MK) $(DISASM_MK)

#FLAGS
CC = gcc
FLAGS = -Wall -Wextra -Werror

#LIBFT
LIBFT_PATH = ./libft/
LIBFT_A = $(LIBFT_PATH)libft.a
LIBFT_NAME = -lft
LIBFT_HEADS =	libft.h \
				ft_printf.h

#HEADERS
COREWAR_HEADERS = ./includes
ASM_HEADERS = $(addprefix $(COREWAR_HEADERS)/, $(ASM_HEADS))
DISASM_HEADERS = $(addprefix $(COREWAR_HEADERS)/, $(DISASM_HEADS))
VM_HEADERS = $(addprefix $(COREWAR_HEADERS)/, $(VM_HEADS))
VM_HEADERS = $(addprefix $(COREWAR_HEADERS)/, $(VS_HEADS))

LIBFT_HEADS_PATH = $(LIBFT_PATH)includes
LIBFT_HEADERS = $(addprefix $(LIBFT_HEADS_PATH)/, $(LIBFT_HEADS))

#COLORS
GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

#OBJECTS
OBJS_DIR = ./objects/
ASM_OBJECTS = $(addprefix $(ASM_PATH)$(OBJS_DIR), $(ASM_OBJS_SRC))
DISASM_OBJECTS = $(addprefix $(DISASM_PATH)$(OBJS_DIR), $(DISASM_OBJS_SRC))
VM_OBJECTS = $(addprefix $(VM_PATH)$(OBJS_DIR), $(VM_OBJS_SRC))
VS_OBJECTS = $(addprefix $(VS_PATH)$(OBJS_DIR), $(VS_OBJS_SRC))

#COMMANDS
all: make_lib $(VM) $(ASM) $(DISASM)

make_lib:
	@$(MAKE) -sC $(LIBFT_PATH)

#MAKE EXEC
$(VM): $(LIBFT_A) $(VM_OBJECTS) $(VS_OBJECTS)
	@$(CC) $(FLAGS) $(VM_OBJECTS) $(VS_OBJECTS) -L$(LIBFT_PATH) $(LIBFT_NAME) $(VS_LIBS) -o $(VM)
	@echo "\n$(GREEN)$(VM) created$(RESET)"

$(ASM): $(LIBFT_A) $(ASM_OBJECTS)
	@$(CC) $(FLAGS) $(ASM_OBJECTS) -L$(LIBFT_PATH) $(LIBFT_NAME) -o $(ASM)
	@echo "\n$(GREEN)$(ASM) created$(RESET)"

$(DISASM): $(LIBFT_A) $(DISASM_OBJECTS)
	@$(CC) $(FLAGS) $(DISASM_OBJECTS) -L$(LIBFT_PATH) $(LIBFT_NAME) -o $(DISASM)
	@echo "\n$(GREEN)$(DISASM) created$(RESET)"

#MAKE OBJECTS
$(ASM_PATH)$(OBJS_DIR)%.o: $(ASM_PATH)%.c $(ASM_HEADERS) $(LIBFT_HEADERS)
	@mkdir -p $(ASM_PATH)$(OBJS_DIR)
	@$(CC) $< $(FLAGS) -c -I$(LIBFT_HEADS_PATH) -I$(COREWAR_HEADERS) -o $@
	@echo "$(GREEN).$(RESET)\c"

$(DISASM_PATH)$(OBJS_DIR)%.o: $(DISASM_PATH)%.c $(DISASM_HEADERS) $(LIBFT_HEADERS)
	@mkdir -p $(DISASM_PATH)$(OBJS_DIR)
	@$(CC) $< $(FLAGS) -c -I$(LIBFT_HEADS_PATH) -I$(COREWAR_HEADERS) -o $@
	@echo "$(GREEN).$(RESET)\c"

$(VM_PATH)$(OBJS_DIR)%.o: $(VM_PATH)%.c $(VM_HEADERS) $(LIBFT_HEADERS)
	@mkdir -p $(VM_PATH)$(OBJS_DIR)
	@$(CC) $< $(FLAGS) -c -I$(LIBFT_HEADS_PATH) -I$(COREWAR_HEADERS) -o $@
	@echo "$(GREEN).$(RESET)\c"

$(VS_PATH)$(OBJS_DIR)%.o: $(VS_PATH)%.c $(VS_HEADERS) $(LIBFT_HEADERS)
	@mkdir -p $(VS_PATH)$(OBJS_DIR)
	@$(CC) $< $(FLAGS) -c -I$(LIBFT_HEADS_PATH) -I$(COREWAR_HEADERS) $(VS_LIBINCS) -o $@
	@echo "$(GREEN).$(RESET)\c"

#MAKE LIB
$(LIBFT_A):
	@$(MAKE) -sC $(LIBFT_PATH)

#CLEAN
clean_lib:
	@$(MAKE) -sC $(LIBFT_PATH) clean

clean:
	@/bin/rm -rf $(ASM_PATH)$(OBJS_DIR) $(DISASM_PATH)$(OBJS_DIR) $(VM_PATH)$(OBJS_DIR) $(VS_PATH)$(OBJS_DIR)

fclean_lib: clean_lib
	@$(MAKE) -sC $(LIBFT_PATH) fclean
	@echo "$(RED)libft deleted$(RESET)"

fclean: fclean_lib clean
	@/bin/rm -f $(VM) $(ASM) $(DISASM)
	@echo "$(RED)$(VM), $(ASM) and $(DISASM) deleted$(RESET)"

re: fclean all
