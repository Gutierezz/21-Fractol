NAME = fractol

SRC_DIR 	= ./srcs
OBJ_DIR 	= ./obj
LIB_DIR 	= ./libft
MLX_DIR 	= ../mlx_test

LIB 		= $(LIB_DIR)/libft.a

FLAGS 		= -Wall -Wextra -Werror -O3 # УДАЛИТЬ ФЛАГ
LIB_LINK	= -lm -lpthread -L $(LIB_DIR) -lft
MLX_LINK 	= -L $(MLX_DIR) -lmlx -lXext -lX11 #-framework OpenGL -framework AppKit

COMP_DIR	= $(SRC_DIR)/complex_funcs
FRACT_DIR	= $(SRC_DIR)/fractals
UTILS_DIR	= $(SRC_DIR)/main_&_utils

COMP_O_DIR	= $(OBJ_DIR)/complex_funcs
FRACT_O_DIR	= $(OBJ_DIR)/fractals
UTILS_O_DIR	= $(OBJ_DIR)/main_&_utils

COMP_FILES	=
FRACT_FILES =
UTILS_FILES =

SRC_FILES 	= main.c fill_area.c image_funcs.c structs_init.c structs_clear.c complex_ops.c get_point_color.c julia_group.c mandel_group.c hook_commands.c complex_arithmetics.c






OBJ_FILES 	= $(addprefix $(OBJ_DIR)/, $(SRC_FILES:%.c=%.o))

CC		  	= gcc
INC		  	= -I $(LIB_DIR)/includes -I includes -I $(MLX_DIR)

all: $(LIB) $(NAME)

$(LIB):
	make -C $(LIB_DIR)

$(NAME): $(OBJ_FILES)
	$(CC) $(FLAGS) $(INC) $(OBJ_FILES) -o $(NAME) $(LIB_LINK) $(MLX_LINK)

$(addprefix $(OBJ_DIR)/, %.o): $(addprefix $(SRC_DIR)/, %.c) | $(OBJ_DIR)
	$(CC) $(FLAGS) $(INC) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

clean:
	rm -rf $(OBJ_DIR)
	make clean -C $(LIB_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIB_DIR)

re: fclean all
