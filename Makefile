NAME = miniRT
S_DIR = srcs
H_DIR = include
SRCS = srcs/main.c \
		srcs/get_next_line.c \
		srcs/struct.c \
		srcs/read_file.c \
		srcs/ft_str_utils.c
OBJS = ${SRCS:.c=.o}
FLAGS = -Wall -Wextra -Werror -Iinclude
MLX = lib/minilibx_opengl
LFT = lib/libft
LIBFLAGS = -Llib/libft -lft -Llib/minilibx_opengl -lmlx -framework OpenGL -framework AppKit


.c.o:
	gcc ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	make -C ${LFT}
	make -C ${MLX}
	gcc ${FLAGS} ${OBJS} ${LIBFLAGS} -o ${NAME}

all: ${NAME}

clean:
	make clean -C ${LFT}
	make clean -C ${MLX}
	rm -f ${OBJS}

fclean: clean
	make fclean -C ${LFT}
	rm -f ${NAME}

re: fclean ${NAME}

bonus:
	${NAME}

.PHONY: all, clean, fclean, re, bonus