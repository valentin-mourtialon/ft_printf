SRCS		=	ft_printf.c

OBJS		=	${SRCS:.c=.o}

LIBFT_PATH	=	./libft

NAME		=	libftprintf.a

CC			=	gcc

FLAGS		=	-Wall -Werror -Wextra

RM			=	rm -f

.c.o:
				${CC} ${FLAGS} -c $< -o ${<:.c=.o}

all:			${NAME}

${NAME}:		${OBJS}
				ar rc ${NAME} ${OBJS}

clean:
				${RM} ${OBJS}

fclean:			clean
				${RM} ${NAME}

re:				fclean all

.PHONY:			all clean fclean re