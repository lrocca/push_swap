# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrocca <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/06 17:24:13 by lrocca            #+#    #+#              #
#    Updated: 2021/05/12 18:54:36 by lrocca           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# compilation options
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror

# directories
SRC		=	./src
OBJ		=	./obj
INC		=	./inc
LIB		=	./lib

# common
COMMON_DIR		=	$(SRC)/common
COMMON_FILES	=	main.c \
					parse.c \
					exit.c \
					print.c \
					exec/swap.c \
					exec/push.c
COMMON_SRC		=	$(addprefix $(COMMON_DIR)/, $(COMMON_FILES))
COMMON_OBJ		=	$(patsubst $(COMMON_DIR)%,$(OBJ)/common%,$(COMMON_SRC:.c=.o))

# checker
CHECKER			=	checker
CHECKER_DIR		=	$(SRC)/$(CHECKER)
CHECKER_FILES	=	main.c \
					exit.c
CHECKER_SRC		=	$(addprefix $(CHECKER_DIR)/, $(CHECKER_FILES))
CHECKER_OBJ		=	$(patsubst $(CHECKER_DIR)%,$(OBJ)/$(CHECKER)%,$(CHECKER_SRC:.c=.o))

# libft
LIBFT_DIR	=	$(LIB)/libft
LIBFT		=	$(LIBFT_DIR)/libft.a

all: $(CHECKER)

$(LIBFT): $(LIBFT_DIR)
	make -C $<

$(CHECKER): $(CHECKER_OBJ) $(COMMON_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJ)/%.o: $(SRC)/%.c $(INC) Makefile
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -I$(INC) -I$(LIBFT_DIR) -c $< -o $@

clean:
	make clean -C $(LIBFT_DIR)
	$(RM) $(CHECKER_OBJ)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	$(RM) -r $(OBJ)
	$(RM) $(CHECKER)

re: fclean all

test: all
	./checker 1 2 3
