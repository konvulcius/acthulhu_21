ASM = asm

ASM_SRC = byte_strings.c \
		  code_analyzer.c \
		  create_champ.c \
		  error_args.c \
		  error_exit.c \
		  fill_instr.c \
		  fill_labels.c \
		  free_all.c \
		  get_instr.c \
		  get_label.c \
		  gnl_spec.c \
		  main.c \
		  name_comment.c \
		  name_comment_helper.c \
		  op.c \
		  print_to_file.c \
		  replace_labels.c \
		  set_argument.c \
		  set_byte_values.c \
		  utils.c \
		  validate_file.c

ASM_OBJS_SRC = $(patsubst %.c, %.o, $(ASM_SRC))
ASM_HEADS =		asm.h \
				op.h \
				errors.h
