VM = corewar

VM_SRC =	main.c \
			parse_args.c \
			parse_utils.c \
			init.c \
			validate.c \
			aff_op.c \
			live_op.c \
			ld_ops.c \
			st_op.c \
			add_sub_ops.c \
			and_or_xor_ops.c \
			zjmp_op.c \
			fork_ops.c \
			ldi_ops.c \
			sti_op.c \
			op.c \
			op_validate.c \
			op_utils.c \
			read_champ.c \
			func_utils.c \
			sp_utils.c \
			champ_utils.c \
			free.c \
			exit.c \
			utils.c \
			game.c

VM_OBJS_SRC = $(patsubst %.c, %.o, $(VM_SRC))
VM_HEADS =		ft_corewar.h \
				vm_structs.h \
				op.h \
				vs.h
