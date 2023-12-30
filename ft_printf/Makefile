
SRCS = srcs/ft_printf.c srcs/ft_itoa.c srcs/ft_uitoa.c srcs/ft_printf_utils.c srcs/ft_printf_ptr_hex.c


OBJS = ${SRCS:.c=.o}


CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

LIBC = ar rcs

NAME = libftprintf.a

INC_DIR = includes
.c.o: libft.h ft_printf.h
	@${CC} ${CFLAGS} -I${INC_DIR} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	@${LIBC} ${NAME} ${OBJS}

all: ${NAME}


clean: 
	@${RM} ${OBJS}

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
