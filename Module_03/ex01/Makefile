# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/14 21:52:44 by dcorenti          #+#    #+#              #
#    Updated: 2023/02/14 21:52:59 by dcorenti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	ScavTrap

SRC				=	main.cpp \
					ClapTrap.cpp \
					ScavTrap.cpp \

OBJS			=	$(SRC:.cpp=.o)

CC				=	clang++

RM				=	rm -rf

CFLAGS			=	-Wall -Wextra -Werror -std=c++98

RESET			=	\033[0m
GREEN			=	\033[38;5;46m
WHITE			=	\033[38;5;15m
GREY			=	\033[38;5;8m
ORANGE			=	\033[38;5;202m
RED				=	\033[38;5;160m

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@echo "$(GREEN)----------------------------------------------------"
	@echo "Executable				./$(NAME) $(RESET)"

$(OBJS): $(SRC)
	@echo "$(GREY)Compiling...				$(RESET)"
	$(CC) $(CFLAGS) -c $(SRC)

all: $(NAME)

clean:
	@echo "$(RED)----------------------------------------------------"
	$(RM) $(OBJS)
	@echo "REMOVED O-FILES $(RESET)"

fclean: clean
	@echo "$(RED)----------------------------------------------------"
	$(RM) $(NAME)
	@echo "REMOVED EXECUTABLE FILE $(RESET)"

re: fclean all

.PHONY: all clean fclean re
