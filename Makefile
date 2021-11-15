# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agirona <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/20 13:58:59 by agirona           #+#    #+#              #
#    Updated: 2021/11/15 16:35:33 by agirona          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCS = philo.c error.c print.c atoi_check.c parsing.c init.c utility.c ft_itoa.c

SRCS_DIR = src

OBJS = $(SRCS:.c=.o)

OBJS_DIR = obj

OBJS_PATH = $(addprefix $(OBJS_DIR)/, $(OBJS))

INC	= include

CFLAGS	= -Wall -Wextra -Werror -I $(INC)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(INC)
	gcc $(CFLAGS) -c $< -o $@

all: create_obj_dir $(NAME)

$(NAME) :	$(OBJS_PATH)
			gcc $(OBJS_PATH) -o $(NAME)

create_obj_dir :
			rm -f obj || true
			mkdir -p obj

clean:
			rm -f $(OBJS_PATH)

fclean:		clean
			rm -f $(NAME)
			rm -rf obj

re:			fclean all

.PHONY:		all create_obj_dir clean fclean re
