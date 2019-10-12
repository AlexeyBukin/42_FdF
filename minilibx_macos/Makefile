NOM=libtrue_mlx.a

SRC= mlx_shaders.c mlx_new_window.m\
mlx_init_loop.m mlx_new_image.m\
mlx_xpm.c mlx_int_str_to_wordtab.c

OBJ1=$(SRC:.c=.o)
OBJ=$(OBJ1:.m=.o)

CFLAGS+=-O2

all: $(NOM)

$(NOM):	$(OBJ)
	@ar rc $(NOM) $(OBJ)
	@ranlib $(NOM)
	@echo "make: Done building \`mlx'."

%.o : %.c
	@clang $(CFLAGS) -c $< -o $@

%.o : %.m
	@clang $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ) *~
	@rm -f mlx_app

fclean:
	@rm -f $(NOM)

re: fclean all