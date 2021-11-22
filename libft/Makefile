ODIR = obj
SRCS = ft_isascii.c ft_isprint.c ft_isalpha.c ft_isdigit.c ft_isalnum.c \
		ft_tolower.c ft_toupper.c ft_strlen.c ft_strlcpy.c ft_strlcat.c \
		ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c \
		ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
		ft_memchr.c ft_memcmp.c ft_strdup.c ft_calloc.c ft_itoa.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_strmapi.c \
		ft_striteri.c
SRCS_BONUS = ${SRCS} ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_front_bonus.c ft_lstadd_back_bonus.c \
			ft_lstnew_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c
OBJS = ${patsubst %.c, ${ODIR}/%.o, ${SRCS}}
OBJS_BONUS = ${patsubst %.c, ${ODIR}/%.o, ${SRCS_BONUS}}

CC = cc
CC_FLAGS = -Wall -Werror -Wextra
RM = rm -rf

NAME = libft.a

${ODIR}/%.o: %.c libft.h
	@mkdir -p ${@D}
	CC ${CC_FLAGS} -c $< -o $@

all: ${NAME}

$(NAME): ${OBJS}
	ar rc ${NAME} ${OBJS}
	ranlib ${NAME}

bonus: ${OBJS_BONUS}
	ar rc ${NAME} ${OBJS_BONUS}
	ranlib ${NAME}

clean:
	${RM} ${ODIR}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: clean fclean re bonus all
