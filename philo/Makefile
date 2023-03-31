NAME=	philo
CC=		gcc
CFLAGS=	 -Wall -Werror -Wextra -pthread 
SECCFLAGS=	 -Wall -Werror -Wextra -pthread -g -fsanitize=thread
RM=		rm -f
SRCS=	srcs/main.c \
		srcs/mutex_safe_action.c \
		srcs/libft_utils.c \
		srcs/philo_utils.c \
		srcs/check_arg.c \
		srcs/checker_routine.c \
		srcs/init_all.c \
		srcs/destroy_all.c \
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
		${CC} ${SECCFLAGS} ${OBJS} ${LIBFT} -g -fsanitize=thread -o ${NAME} 

.PHONY:		all clean fclean re
