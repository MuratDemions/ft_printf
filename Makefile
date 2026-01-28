NAME = libft.a

CC = cc

CFLAGS = -Wall -Werror -Wextra

AR = ar rcs

RM = rm -f

SRCS = ft_printf.c ft_putchar.c ft_putstr.c ft_putdec.c ft_puthex.c

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