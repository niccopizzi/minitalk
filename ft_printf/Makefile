CFLAGS = -Wall -Wextra -Werror 

NAME = libftprintf.a 

MY_SOURCES = ft_printf.c \
		tools_one.c \
		tools_two.c

MY_OBJECTS = $(MY_SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(MY_OBJECTS)
	@ar rc $(NAME) $(MY_OBJECTS)
	@ranlib $(NAME)
	@echo "$(NAME) compiled."

%.o :%.c
	@cc $(CFLAGS) -c $< -o $@ 
	@echo "$< compiled."

clean:
	@$(RM) $(MY_OBJECTS)
	@echo "Objects files removed."

fclean: clean
	@$(RM) $(NAME)
	@echo "$(NAME) removed."

re: fclean all

.PHONY: all clean fclean re 