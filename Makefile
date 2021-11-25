SRCS = $(shell find src -name "*.c" -type f)
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

bonus: all

clean:
	${MAKE} $@ -C ${LIBFT}
	${RM} ${OBJS}

fclean: clean
	${MAKE} $@ -C ${LIBFT}
	${RM} ${NAME}

re: fclean all

.PHONY: clean fclean re all ${LIBFT}
