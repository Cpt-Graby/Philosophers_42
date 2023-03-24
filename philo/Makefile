NAME=	philo
CC=		gcc
CFLAGS=	 -Wall -Werror -Wextra -pthread
RM=		rm -f
SRCS=	srcs/main.c \
		srcs/utils.c \
		srcs/ft_ltoa.c \
		srcs/print_stamp.c \
		srcs/check_arg.c \
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
		${CC} ${CFLAGS} ${OBJS} -o ${NAME} 

${NAME}:	${OBJS}

clean:		
		${RM} ${OBJS}

fclean:		clean
		${RM} ${NAME}

re:		fclean all

t:	${NAME}
		${CC} ${CFLAGS} ${OBJS} ${LIBFT} -g -fsanitize=thread -o ${NAME} 

.PHONY:		all clean fclean re
