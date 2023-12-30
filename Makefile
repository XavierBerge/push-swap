SRCS = srcs/algorithm/sorts.c srcs/errors_and_utils/errors.c srcs/errors_and_utils/utils.c \
       srcs/instructions/push.c srcs/instructions/reverse_rotate.c srcs/instructions/rotate.c \
       srcs/instructions/swap.c srcs/main_and_init_stacks/push_swap.c srcs/algorithm/prep_a.c \
       srcs/algorithm/utils.c srcs/algorithm/prep_b.c srcs/errors_and_utils/free.c

LIBFT = libft.a
PRINTF = libftprintf.a
OBJS = ${SRCS:.c=.o}
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -f
NAME = push_swap
INC_DIR = includes

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

%.o: %.c
	@${CC} ${CFLAGS} -I${INC_DIR} -c $< -o $@
	@echo "${GREEN}Compilation of $< successful.${RESET}"

${NAME}: ${OBJS}
	@make -s -C libft
	@cp libft/libft.a . && echo "${GREEN}Libft compiled successfully.${RESET}"
	@make -s -C ft_printf
	@cp ft_printf/libftprintf.a . && echo "${GREEN}Printf compiled successfully.${RESET}"
	@${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIBFT} ${PRINTF}
	@echo "${GREEN}Executable ${NAME} compiled successfully.${RESET}"

all : ${NAME}

clean:
	@make -s clean -C libft
	@make -s clean -C ft_printf
	@${RM} ${OBJS}
	@echo "${GREEN}Clean successful.${RESET}"

fclean : clean
	@make -s fclean -C libft
	@make -s fclean -C ft_printf
	@${RM} ${NAME}
	@${RM} ${LIBFT}
	@${RM} libft/${LIBFT}
	@${RM} ${PRINTF}
	@${RM} ft_printf/${PRINTF}
	@echo "${GREEN}FClean successful.${RESET}"

re : fclean all

.PHONY: all clean fclean re

