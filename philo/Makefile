NAME=	philo
CC=		gcc
CFLAGS=	-Wall -Werror -Wextra
RM=		rm -f
LIBFT=	-L../lib42 -lft
SRCS=	srcs/main.c 
OBJS=	$(SRCS:.c=.o)

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all:	${NAME}
		make -C ../lib42
		${CC} ${CFLAGS} ${OBJS} -o ${NAME} 

${NAME}:	${OBJS}

clean:		
		make clean -C ../lib42
		${RM} ${OBJS}
		${RM} ${OBJSB}

fclean:		clean
		make fclean -C ../lib42
		${RM} ${NAME}

re:		fclean all

.PHONY:		all clean fclean re
