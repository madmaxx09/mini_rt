PROG    = mini_rt

SRCS    = main.c store_data.c store_more.c utils.c print_args.c
OBJS    = ${SRCS:.c=.o}

CC      = gcc
CFLAGS  = -Wall -Wextra -Werror -g

.c.o:
	@gcc ${CFLAGS} -c $< -o $@

all:    ${PROG}

${PROG}: ${OBJS}
	@echo "Compiling...\n"
	@make -C ./LIBFT # Changed 'make re' to 'make'
	@$(CC) ${OBJS} -L./LIBFT -lft -o ${PROG} # Changed '-Llibft' to '-L./LIBFT'
	@echo "mini_rt compiled"

clean:
	@make clean -C ./LIBFT
	@rm -f ${OBJS} ${OBJS_B}
	@echo "Cleaned\n"

fclean: clean
	@make fclean -C ./LIBFT
	@rm -f $(NAME)
	@rm -f ${PROG}
	@echo "F_Cleaned\n"

re:     fclean all

.PHONY: all clean fclean re
