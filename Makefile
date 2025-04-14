# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npizzi <npizzi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/31 12:40:35 by npizzi            #+#    #+#              #
#    Updated: 2024/10/31 13:15:25 by npizzi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror 

NAME = minitalk

LIBFT_PATH = ./libft/
LIBFT = $(LIBFT_PATH)libft.a

PRINTF_PATH = ./ft_printf/
PRINTF = $(PRINTF_PATH)libftprintf.a

CLIENT_SOURCE = client.c

SERVER_SOURCE = server.c

all: $(NAME)

$(NAME): server client

$(PRINTF):
	@make -C ft_printf
	
$(LIBFT):
	@make -C libft

server: $(LIBFT) $(PRINTF) $(SERVER_SOURCE)
	@cc $(CFLAGS) server.c -o server $(LIBFT) $(PRINTF)
	@echo "Server compiled."

client: $(LIBFT) $(PRINTF) $(CLIENT_SOURCE)
	@cc $(CFLAGS) client.c -o client $(LIBFT) $(PRINTF)
	@echo "Client compiled"


%.o :%.c
	@cc $(CFLAGS) -c $< -o $@ 
	@echo "$< compiled."

clean:
	@make -C $(LIBFT_PATH) clean
	@make -C $(PRINTF_PATH) clean

fclean: clean
	@make -C $(LIBFT_PATH) fclean
	@make -C $(PRINTF_PATH) fclean
	@rm -f server client 
	@echo "Server and Client executables removed."

re: fclean all

.PHONY: all server client clean re  

