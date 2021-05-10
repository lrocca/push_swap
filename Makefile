# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrocca <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/06 17:24:13 by lrocca            #+#    #+#              #
#    Updated: 2021/05/10 19:56:18 by lrocca           ###   ########.fr        #
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

# checker
CHECKER			=	checker
CHECKER_DIR		=	$(SRC)/$(CHECKER)
CHECKER_FILES	=	main.c
CHECKER_SRC		=	$(addprefix $(CHECKER_DIR)/, $(CHECKER_FILES))
CHECKER_OBJ		=	$(patsubst $(CHECKER_DIR)%,$(OBJ)/$(CHECKER)%,$(CHECKER_SRC:.c=.o))

# libft
LIBFT_DIR	=	$(LIB)/libft
LIBFT		=	$(LIBFT_DIR)/libft.a

all: $(CHECKER)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(CHECKER): $(CHECKER_OBJ) $(LIBFT)
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
