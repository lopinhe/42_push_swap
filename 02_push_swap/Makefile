# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsasse <lsasse@student.42berlin.de>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/14 18:55:45 by lsasse            #+#    #+#              #
#    Updated: 2024/03/05 19:19:18 by lsasse           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ------------------------------ Sources ------------------------------

# Files
PUSH_SWAP		=	src/push_swap.c \
					src/push_swap_utils.c \
					src/input_handling/check_args.c \
					src/input_handling/check_args_utils.c \
					src/input_handling/stack_operations_1.c \
					src/input_handling/stack_operations_2.c \
					src/output_handling/optimize_output.c \
					src/output_handling/commands_1.c \
					src/output_handling/commands_2.c \
					src/output_handling/queue_operations_1.c \
					src/output_handling/queue_operations_2.c \
					src/sort/sort_big.c \
					src/sort/sort_small.c \
					src/sort/sort.c \
					src/sort/sort_utils/sort_utils.c \
					src/sort/sort_utils/find_data.c \
					src/sort/sort_utils/find_index.c \

LIBFT		=	cd libft && make

LIB			=	libft/libft.a

# Sources and objects
PUSH_SWAP_SRC	=	$(PUSH_SWAP)

PUSH_SWAP_OBJS	=	$(PUSH_SWAP_SRC:.c=.o)

OBJS		=	$(PUSH_SWAP_OBJS)

# ------------------------------ Constant strings ------------------------------

GCC			=	cc

FLAGS		=	-Wall -Wextra -Werror

INCLUDE		=	-I inc

PUSH_SWAP_NAME	=	push_swap

NAME		=	push_swap

# ------------------------------ Colors ------------------------------

BOLD_PURPLE	=	\033[1;35m

BOLD_CYAN	=	\033[1;36m

BOLD_YELLOW	=	\033[1;33m

NO_COLOR	=	\033[0m

# ------------------------------ Messages ------------------------------

COMP_START	=	echo "\n🚧 $(BOLD_YELLOW)Make: $(NO_COLOR)Starting the compilation...\n"

CLI_READY	=	echo "\n📟 push_swap programm is ready!\n"

CLEANED		=	echo "\n💧 $(BOLD_YELLOW)Clean: $(NO_COLOR)Removed all the \".o\" files \n"

FCLEANED	=	echo "\n🧼 $(BOLD_YELLOW)Fclean: $(NO_COLOR)Removed the executables \n"

# ------------------------------ Rules ------------------------------

all: $(NAME)

$(NAME): comp_start ft_push_swap

comp_start:
	@$(COMP_START)
	@$(LIBFT)

ft_push_swap: $(PUSH_SWAP_OBJS)
	@$(GCC) $(FLAGS) $(PUSH_SWAP_OBJS) $(LIB) -o $(PUSH_SWAP_NAME)
	@$(PUSH_SWAP_READY)

clean:
	@rm -rf $(OBJS)
	@cd libft && make clean
	@$(CLEANED)

fclean: clean
	@rm -rf $(PUSH_SWAP_NAME)
	@cd libft && make fclean
	@$(FCLEANED)

.c.o:
	@${GCC} ${FLAGS} $(INCLUDE) -c $< -o ${<:.c=.o}

re:	fclean all

.PHONY: all clean fclean re libft