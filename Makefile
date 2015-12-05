# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/25 15:50:19 by zcarde            #+#    #+#              #
#    Updated: 2015/08/06 20:03:28 by zcarde           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in


SRC = ants.c \
command.c \
djikstra.c \
djisktra2.c \
error.c \
lemin.c \
pipe.c \
prints.c \
rooms.c \
rooms2.c \
start.c \
successors.c \
ways.c \
ways2.c

OBJ = $(SRC:.c=.o)

FLAG = -Wall -Werror -Wextra -ggdb3

LIBFT = libft -lft

INCLUDES = -I libft/includes

.PHONY : libft.a
# all: libft.a $(NAME)
# 	gcc $(FLAG) $(SRC) $(INCLUDES) -L$(LIBFT) -o $(NAME)
# libft.a:
# 	@$(MAKE) -C ./libft

# $(NAME): $(OBJ)
# 	gcc $(FLAG) $(OBJ) $(INCLUDES) -L$(LIBFT) -o $(NAME)

# %.o: %.c
# 	gcc $(FLAG) $(INCLUDES) -c $^

all: libft.a $(NAME)

libft.a:
	@$(MAKE) -C ./libft

$(NAME): $(OBJ)
	gcc $(FLAG) $(OBJ) $(INCLUDES) -L$(LIBFT) -o $(NAME)

%.o: %.c
	gcc $(FLAG) $(INCLUDES) -c $^

clean :
	@make clean -C ./libft
	rm -f $(OBJ)

fclean : clean
	rm -f libft.a
	rm -f $(NAME)

re : fclean all
