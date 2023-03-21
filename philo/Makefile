NAME=	philo
CC=		gcc
CFLAGS=	 -Wall -Werror -Wextra -pthread
RM=		rm -f
LIBFT=	-L../lib42 -lft
SRCS=	srcs/main.c \
		srcs/init_all.c \
		srcs/destroy_all.c \
		srcs/time_utils.c \
		srcs/philo_thread.c \
		srcs/one_philo.c \
		srcs/philo_routine.c 
OBJS=	$(SRCS:.c=.o)

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all:	${NAME}
		make -C ../lib42
		${CC} ${CFLAGS} ${OBJS} ${LIBFT} -o ${NAME} 

t:	${NAME}
		make -C ../lib42
		${CC} ${CFLAGS} ${OBJS} ${LIBFT} -g -fsanitize=thread -o ${NAME} 
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
