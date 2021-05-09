NAME = miniRT
S_DIR = srcs
H_DIR = include
SRCS_FILES = main.c \
		get_next_line.c \
		handle_errors.c \
		rt.c \
		parse.c \
		ft_stris.c \
		ft_atof.c \
		tabchar.c
SRCS = $(addprefix ${S_DIR}/, ${SRCS_FILES})
OBJS = ${SRCS:.c=.o}
FLAGS = -Wall -Wextra -Werror -I${H_DIR}
MLX = lib/minilibx_opengl
LFT = lib/libft
LIBFLAGS = -Llib/libft -lft -Llib/minilibx_opengl -lmlx -framework OpenGL -framework AppKit


.c.o:
	gcc ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	make -C ${LFT}
	make -C ${MLX}
	gcc ${FLAGS} ${LIBFLAGS} ${OBJS} -o ${NAME}

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