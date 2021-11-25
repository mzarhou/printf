ODIR = obj
HEADERS =  libft/libft.h \
		 src/bonus_utils/ft_printf_bonus_utils.h \
		 src/ft_printf.h \
		 src/makers/ft_format.h \
		 src/makers/ft_printf_makers.h \
		 src/utils/ft_printf_utils.h \
		 src/utils.h

SRCS_BONUS_UTILS = ft_init_format.c \
		ft_padd.c \
		ft_padd_left.c \
		ft_padd_right.c \
		ft_parse_format.c

SRCS_MAKERS = ft_makeaddr.c \
		ft_makechar.c \
		ft_makehexa.c \
		ft_makeint.c \
		ft_makestr.c \
		ft_makeuint.c

SRCS_UTILS = assign_free.c \
		char2str.c \
		get_format.c \
		ft_utoa.c \
		strjoin_free.c \
		uint2hexa.c \
		uint2hexa8.c

_SRCS = printf.c \
		${patsubst %.c, bonus_utils/%.c, ${SRCS_BONUS_UTILS}} \
		${patsubst %.c, makers/%.c, ${SRCS_MAKERS}} \
		${patsubst %.c, utils/%.c, ${SRCS_UTILS}}
SRCS = ${patsubst %.c, src/%.c, ${_SRCS}}

OBJS = ${patsubst %.c, ${ODIR}/%.o, ${SRCS}} \
		libft/obj/ft_atoi.o \
		libft/obj/ft_bzero.o \
		libft/obj/ft_calloc.o \
		libft/obj/ft_isalnum.o \
		libft/obj/ft_isalpha.o \
		libft/obj/ft_isascii.o \
		libft/obj/ft_isdigit.o \
		libft/obj/ft_isprint.o \
		libft/obj/ft_itoa.o \
		libft/obj/ft_lstadd_back_bonus.o \
		libft/obj/ft_lstadd_front_bonus.o \
		libft/obj/ft_lstclear_bonus.o \
		libft/obj/ft_lstdelone_bonus.o \
		libft/obj/ft_lstiter_bonus.o \
		libft/obj/ft_lstlast_bonus.o \
		libft/obj/ft_lstmap_bonus.o \
		libft/obj/ft_lstnew_bonus.o \
		libft/obj/ft_lstsize_bonus.o \
		libft/obj/ft_memchr.o \
		libft/obj/ft_memcmp.o \
		libft/obj/ft_memcpy.o \
		libft/obj/ft_memmove.o \
		libft/obj/ft_memset.o \
		libft/obj/ft_putchar_fd.o \
		libft/obj/ft_putendl_fd.o \
		libft/obj/ft_putnbr_fd.o \
		libft/obj/ft_putstr_fd.o \
		libft/obj/ft_split.o \
		libft/obj/ft_strchr.o \
		libft/obj/ft_strdup.o \
		libft/obj/ft_striteri.o \
		libft/obj/ft_strjoin.o \
		libft/obj/ft_strlcat.o \
		libft/obj/ft_strlcpy.o \
		libft/obj/ft_strlen.o \
		libft/obj/ft_strmapi.o \
		libft/obj/ft_strncmp.o \
		libft/obj/ft_strnstr.o \
		libft/obj/ft_strrchr.o \
		libft/obj/ft_strtrim.o \
		libft/obj/ft_substr.o \
		libft/obj/ft_tolower.o \
		libft/obj/ft_toupper.o

NAME = libftprintf.a
LIBFT = libft
RM = rm -rf
CC = cc
CC_FLAGS = -Wall -Werror -Wextra

${ODIR}/%.o: %.c $(HEADERS)
	@mkdir -p ${@D}
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
	${RM} ${ODIR}

fclean: clean
	${MAKE} $@ -C ${LIBFT}
	${RM} ${NAME}

re: fclean all

.PHONY: clean fclean re all ${LIBFT}
