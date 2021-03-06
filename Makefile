# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrocca <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/06 17:24:13 by lrocca            #+#    #+#              #
#    Updated: 2021/09/24 14:53:52 by lrocca           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# compilation options
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror

# directories
SRC		=	./src
OBJ		=	./obj
INC		=	./inc

# common
COMMON			=	common
COMMON_DIR		=	$(SRC)/$(COMMON)
COMMON_FILES	=	main.c \
					check.c \
					cmd.c \
					exit.c \
					parse.c \
					print.c \
					exec/exec.c \
					exec/push.c \
					exec/reverse.c \
					exec/rotate.c \
					exec/swap.c \
					utils/print.c
COMMON_SRC		=	$(addprefix $(COMMON_DIR)/, $(COMMON_FILES))
COMMON_OBJ		=	$(patsubst $(COMMON_DIR)%,$(OBJ)/$(COMMON)%,$(COMMON_SRC:.c=.o))

# checker
CHECKER			=	checker
CHECKER_DIR		=	$(SRC)/$(CHECKER)
CHECKER_FILES	=	main.c \
					read.c \
					exit.c
CHECKER_SRC		=	$(addprefix $(CHECKER_DIR)/, $(CHECKER_FILES))
CHECKER_OBJ		=	$(patsubst $(CHECKER_DIR)%,$(OBJ)/$(CHECKER)%,$(CHECKER_SRC:.c=.o))

# push_swap
PUSH_SWAP			=	push_swap
PUSH_SWAP_DIR		=	$(SRC)/$(PUSH_SWAP)
PUSH_SWAP_FILES		=	main.c \
						calc.c \
						lis.c \
						sort/3.c \
						sort/5.c \
						sort/n.c \
						utils/stack_len.c \
						utils/stack_to_array.c \
						exit.c
PUSH_SWAP_SRC		=	$(addprefix $(PUSH_SWAP_DIR)/, $(PUSH_SWAP_FILES))
PUSH_SWAP_OBJ		=	$(patsubst $(PUSH_SWAP_DIR)%,$(OBJ)/$(PUSH_SWAP)%,$(PUSH_SWAP_SRC:.c=.o))

# libft
LIBFT_DIR	=	./libft
LIBFT		=	$(LIBFT_DIR)/libft.a

all: $(CHECKER) $(PUSH_SWAP)

$(LIBFT): $(LIBFT_DIR)
	make -C $<

$(CHECKER): $(CHECKER_OBJ) $(COMMON_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@

$(PUSH_SWAP): $(PUSH_SWAP_OBJ) $(COMMON_OBJ) $(LIBFT)
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
	./test/test.sh

norm: all
	clear
	norminette | grep Error
