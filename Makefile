NAME = fractol

SRC_DIR 	= ./srcs
OBJ_DIR 	= ./obj
LIB_DIR 	= ./libft
MLX_DIR 	= ../mlx_test # перелинковать на маке

LIB 		= $(LIB_DIR)/libft.a

COMP_DIR	= $(SRC_DIR)/complex_funcs
FRACT_DIR	= $(SRC_DIR)/fractals
UTILS_DIR	= $(SRC_DIR)/utils

COMP_O_DIR	= $(OBJ_DIR)/complex_funcs
FRACT_O_DIR	= $(OBJ_DIR)/fractals
UTILS_O_DIR	= $(OBJ_DIR)/utils

COMP_FILES	= complex_arithmetics.c complex_ops.c
FRACT_FILES = julia_group.c mandel_group.c newton_group.c
UTILS_FILES = structs_clear.c structs_init.c fill_area.c get_point_color.c hook_commands.c key_press_utils.c image_funcs.c main.c

COMP_OBJ	= $(addprefix $(COMP_O_DIR)/, $(COMP_FILES:%.c=%.o))
FRACT_OBJ 	= $(addprefix $(FRACT_O_DIR)/, $(FRACT_FILES:%.c=%.o))
UTILS_OBJ 	= $(addprefix $(UTILS_O_DIR)/, $(UTILS_FILES:%.c=%.o))


CC		  	= gcc
INC		  	= -I $(LIB_DIR)/includes -I includes -I $(MLX_DIR)
FLAGS 		= -Wall -Wextra -Werror -O3# УДАЛИТЬ ФЛАГ
LIB_LINK	= -lm -lpthread -L $(LIB_DIR) -lft
MLX_LINK 	= -L $(MLX_DIR) -lmlx -lXext -lX11 #-framework OpenGL -framework AppKit


all: $(LIB) $(NAME)

$(LIB):
	make -C $(LIB_DIR)

$(NAME): $(COMP_OBJ) $(FRACT_OBJ) $(UTILS_OBJ)
	$(CC) $(FLAGS) $(INC) $(COMP_OBJ) $(FRACT_OBJ) $(UTILS_OBJ) -o $(NAME) $(LIB_LINK) $(MLX_LINK)

$(addprefix $(COMP_O_DIR)/, %.o): $(addprefix $(COMP_DIR)/, %.c) | $(COMP_O_DIR)
	$(CC) $(FLAGS) $(INC) -c $< -o $@

$(addprefix $(FRACT_O_DIR)/, %.o): $(addprefix $(FRACT_DIR)/, %.c) | $(FRACT_O_DIR)
	$(CC) $(FLAGS) $(INC) -c $< -o $@

$(addprefix $(UTILS_O_DIR)/, %.o): $(addprefix $(UTILS_DIR)/, %.c) | $(UTILS_O_DIR)
	$(CC) $(FLAGS) $(INC) -c $< -o $@


$(COMP_O_DIR):
	mkdir -p $@

$(FRACT_O_DIR):
	mkdir -p $@

$(UTILS_O_DIR):
	mkdir -p $@

clean:
	rm -rf $(OBJ_DIR)
	make clean -C $(LIB_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIB_DIR)

re: fclean all
