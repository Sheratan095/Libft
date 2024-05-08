NAME		= libft.a

SRCS		= *.c


OBJS		= $(SRCS:%.c=%.o)


FLAGS		= -Wall -Werror -Wextra

$(NAME):
	gcc $(FLAGS) -c $(SRCS) *.h -I ./
	ar rc $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(NAME)
