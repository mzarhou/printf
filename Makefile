SRCS = $(shell find . -name "*.c" -not -name "main.c" -type f)
OBJS = ${SRCS:.c=.o}

NAME = libftprintf.a

all: $(NAME) $(exe)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

exe:
	gcc main.c $(NAME) -o a.out
