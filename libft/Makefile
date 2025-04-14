CFLAGS = -Wall -Wextra -Werror -std=c99

NAME = libft.a 

MY_SOURCES =    ft_abs.c          \
                ft_atoc.c         \
                ft_atoi.c         \
                ft_atol.c         \
                ft_bzero.c        \
                ft_calloc.c       \
                ft_isalnum.c      \
                ft_isalpha.c      \
                ft_isascii.c      \
                ft_isdigit.c      \
                ft_isspace.c      \
                ft_isprint.c      \
                ft_itoa.c         \
                ft_max.c          \
                ft_memchr.c       \
                ft_memcmp.c       \
                ft_memcpy.c       \
                ft_memmove.c      \
                ft_memset.c       \
                ft_min.c          \
                ft_numlen.c       \
                ft_pow.c          \
                ft_putchar_fd.c   \
                ft_putendl_fd.c   \
                ft_putnbr_fd.c    \
                ft_putstr_fd.c    \
                ft_split.c        \
                ft_strchr.c       \
                ft_strcmp.c       \
                ft_strdup.c       \
                ft_striteri.c     \
                ft_strjoin.c      \
                ft_strlcat.c      \
                ft_strlcpy.c      \
                ft_strlen.c       \
                ft_strmapi.c      \
                ft_strncmp.c      \
                ft_strnstr.c      \
                ft_strrchr.c      \
                ft_strtod.c       \
                ft_strtrim.c      \
                ft_substr.c       \
                ft_tolower.c      \
                ft_toupper.c      \
                ./get_next_line/get_next_line.c         \
                ./get_next_line/get_next_line_utils.c   

	    
MY_BONUS =      ft_lstadd_back.c    \
                ft_lstadd_front.c   \
                ft_lstclear.c       \
                ft_lstdelone.c      \
                ft_lstiter.c        \
                ft_lstlast.c        \
                ft_lstmap.c         \
                ft_lstnew.c         \
                ft_lstsize.c        \
                ./get_next_line/get_next_line_bonus.c   \
                ./get_next_line/get_next_line_utils_bonus.c 


MY_OBJECTS = $(MY_SOURCES:.c=.o)

MY_OBJECTS_BONUS = $(MY_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(MY_OBJECTS)
	@ar rc $(NAME) $(MY_OBJECTS)
	@ranlib $(NAME)
	@echo "$(NAME) compiled."

%.o :%.c
	@cc $(CFLAGS) -c $< -o $@ 
	@echo "$< compiled."

bonus: $(MY_OBJECTS) $(MY_OBJECTS_BONUS)
	@ar rc $(NAME) $(MY_OBJECTS) $(MY_OBJECTS_BONUS)
	@ranlib $(NAME)
	@echo "$(NAME) compiled with bonus."


clean:
	@$(RM) $(MY_OBJECTS) $(MY_OBJECTS_BONUS)
	@echo "Objects files removed."

fclean: clean
	@$(RM) $(NAME)
	@echo "$(NAME) removed."

re: fclean all

.PHONY: all clean fclean re bonus 

