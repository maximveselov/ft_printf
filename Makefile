NAME = libftprintf.a

CC = gcc

LIBFT = libft.a

CFLAGS = -Wall -Wextra -Werror

INCLUDES =	ft_printf.h \
				libft.h 

SRCS = 

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) 
	ar rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
