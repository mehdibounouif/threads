CC = cc
FLAGS = -g
NAME = exercise3
SRC = main.c
OBJ = ${SRC:.c=.o}

%.c: %.o
	${CC} ${FLAGS} $< -o $@

${NAME}: ${OBJ}
	${CC} ${FLAGS} ${OBJ} -o ${NAME}

all: ${NAME}

clean:
	rm -rf *.o 

fclean: clean 
	rm -rf ${NAME}

re: fclean all

.PHONY: all re fclean clean
