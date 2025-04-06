FLAGS = -g
CC = cc
NAME = exercise
SRC = main.c
OBJS = ${SRC:.c=.o}
all: ${NAME}
${NAME}: ${OBJS}
	${CC} ${FLAGS} ${OBJS} -o ${NAME}

%.c: %.o
	${CC} ${FLAGS} $< -o $@

clean:
	rm -rf *.o

fclear: clean
	rm -rf ${NAME}

re: fclean all

.PHONY: clean fclean all re

