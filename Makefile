NAME = libftprintf.a

all: ${NAME}

${NAME}:
	gcc -Wall -Werror -Wextra -c ft_*.c
	ar rc ${NAME} ft_*.o

clean:
	rm -rf ft_*.o

fclean: clean
	rm -rf ${NAME}

re: fclean all
