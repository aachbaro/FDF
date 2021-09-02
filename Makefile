NAME = fdf
SRC = SRCS/main.c \
      SRCS/drawing.c \
      SRCS/parsing.c \
      SRCS/utils1.c \
      SRCS/window.c \
      SRCS/draw_grid.c \
      SRCS/handle.c \

LIBFT = -L./LIBFT -lft
#MLX = -I/usr/local/include -L/usr/local/lib -lmlx -framework OpenGL -framework AppKit
MLX = -L./../MLX -lmlx -lXext -lX11 -lm
CC = gcc #clang
INC = -I./fdf.h
CFLAGS = -Wall -Wextra -Werror #-g3 -fsanitize=address
RM = rm -rf
OBJ = $(SRC:.c=.o)
$(NAME): $(OBJ)
	@$(MAKE) -C ./LIBFT
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(INC) $(LIBFT) $(MLX)
all: $(NAME)
clean:
	@${RM} ${OBJ}
fclean: clean
	@$(MAKE) fclean -C ./LIBFT
	@${RM} ${SAVE}
	@${RM} ${NAME}
re: fclean all
.PHONY: all clean fclean re
