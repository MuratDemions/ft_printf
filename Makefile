NAME = libforprintf.a

CC = cc

CFLAGS = -Wall -Werror -Wextra

AR = ar rcs

RM = rm -f

SRCS = ft_printf.c ft_str.c ft_num.c

OBJS = ${SRCS:.c=.o}

all: $(NAME)

$(NAME): ${OBJS}
		${AR} ${NAME} ${OBJS}

clean:
	${RM} ${OBJS}

fclean:
	${RM} ${OBJS} ${NAME}

re: fclean all
		
.PHONY: all  clean fclean re