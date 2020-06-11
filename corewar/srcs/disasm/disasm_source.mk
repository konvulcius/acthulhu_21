DISASM = dis_asm

DISASM_SRC =	check_args.c \
				check_args_2.c \
				filling_out.c \
				init_free.c \
				main.c \
				op.c \
				open_and_check_instr.c

DISASM_OBJS_SRC = $(patsubst %.c, %.o, $(DISASM_SRC))
DISASM_HEADS =		dis_asm.h \
					op.h
