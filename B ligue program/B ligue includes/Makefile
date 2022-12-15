NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SOURCES = $(wildcard *.c)

BONUS_SOURCES = $(wildcard ft_lst*.c)

OBJECTS = $(SOURCES:.c=.o)

BONUS_OBJECTS = $(BONUS_SOURCES:.c=.o)

RM = rm -f

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME) $(bonus)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

bonus: $(BONUS_OBJECTS)
	ar rcs $(NAME) $(BONUS_OBJECTS)

clean: 
	$(RM) $(OBJECTS)
	$(RM) $(BONUS_OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
