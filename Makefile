NAME = libftprintf.a

CC = gcc

LIBFT = libft

LIBFT_SRC = ./libft/libft.a

LIBFT_DEST = ./sources/libft.a

CFLAGS =  -Wall -Wextra -Werror

HEADER = ./sources/ft_printf.h

FILES =	fill_flags.c \
			flags_utils.c \
			ft_printf.c \
			ft_putstr.c \
			num_utils.c \
			print_char.c \
			print_hexa.c \
			print_integer.c \
			print_pointer.c \
			print_string.c \
			print_uint.c \
			print_utils.c \
			print_percent.c 

SRCS_DIR = sources

SRCS = $(addprefix $(SRCS_DIR)/, $(FILES))

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT)
	cp $(LIBFT_SRC) $(NAME)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
