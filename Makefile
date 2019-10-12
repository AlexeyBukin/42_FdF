NAME = fdf

FLAGS = -Wall -Wextra -Werror

INCLUDES = includes/

O_DIR = objects/
C_DIR = src/

LIB_FT_DIR = libft/
LIB_FT_FILE = $(LIB_FT_DIR)/libft.a

LIB_X_DIR = minilibx_macos/
LIB_X_FILE = $(LIB_X_DIR)/libtrue_mlx.a

GNL_DIR = gnl/
GNL_FILE = $(GNL_DIR)/get_next_line.c
GNL_OBJ = $(O_DIR)/get_next_line.o

LIB_FLAGS = -L $(LIB_X_DIR) -L $(LIB_FT_DIR) -ltrue_mlx -lft -I $(GNL_DIR)

FRAMEWORKS = -framework OpenGL -framework AppKit

#ls *.c
C_FILES_LIST = main.c draw_simple_line.c printables.c test.c \
convert_coords.c utilities.c



C_FILES	= $(addprefix $(C_DIR), $(C_FILES_LIST))

O_FILES_LIST = $(patsubst %.c, %.o, $(C_FILES_LIST))
O_FILES	= $(addprefix $(O_DIR), $(O_FILES_LIST))

.PHONY: clean fclean

all: $(NAME)

$(NAME): $(LIB_FT_FILE) $(LIB_X_FILE) $(O_DIR) $(GNL_OBJ) $(O_FILES)
	@clang $(FLAGS) -o $(NAME) $(O_FILES) $(LIB_FLAGS) $(FRAMEWORKS)
	@echo "make: Done building \`fdf'."

$(O_DIR):
	@mkdir -p $(O_DIR)

$(GNL_OBJ): $(GNL_FILE)
	@clang $(FLAGS) -I $(INCLUDES) -I $(LIB_FT_DIR) -I $(LIB_X_DIR) -o $@ -c $<
	@echo "make: Done building \`gnl'."

$(LIB_FT_FILE):
	@make -C $(LIB_FT_DIR)

$(LIB_X_FILE):
	@make -C $(LIB_X_DIR)

$(O_DIR)%.o: $(C_DIR)%.c
	@clang $(FLAGS) -I $(INCLUDES) -I $(LIB_FT_DIR) -I $(LIB_X_DIR) -I $(GNL_DIR) -o $@ -c $<

clean:
	@make -C $(LIB_FT_DIR) clean
	@make -C $(LIB_X_DIR) clean
	@rm -rf $(O_DIR)

fclean: clean
	@make -C $(LIB_FT_DIR) fclean
	@make -C $(LIB_X_DIR) fclean
	@rm -f $(NAME)

re: fclean all