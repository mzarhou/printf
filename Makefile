SRCS = $(shell find . -name "*.c" -not -name "main.c" -maxdepth 1 -type f)
OBJS = ${SRCS:.c=.o} $(shell find libft/obj -name "*.o")

NAME = libftprintf.a
LIBFT = libft
RM = rm -rf
CC = cc
CC_FLAGS = -Wall -Werror -Wextra

%.o: %.c
	${CC} ${CFLAG} -c $< -o $@

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

$(LIBFT):
	${MAKE} -C ${LIBFT}

clean:
	${RM} ${ODIR}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: clean fclean re all ${LIBFT}
