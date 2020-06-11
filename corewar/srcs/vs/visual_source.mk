VS_SRC =	vs_init.c \
			vs.c \
			cycle.c \
			menu.c \
			vs_utils.c \
			get_utils.c \
			init_regs.c \
			regs.c \
			mutable.c \
			names.c \
			glyph_array.c \
			winner.c \
			carriage.c \
			vs_free.c \
			exit.c

VS_OBJS_SRC = $(patsubst %.c, %.o, $(VS_SRC))
VS_HEADS =		ft_corewar.h \
				vm_structs.h \
				op.h \
				vs.h

VS_LIBS = -L./libsdl/ -lSDL2 -L./libttf/ -lSDL2_ttf
VS_LIBINCS = -I/usr/local/include/SDL2 -I/opt/X11/include -D_THREAD_SAFE -I/opt/X11/include/freetype2
