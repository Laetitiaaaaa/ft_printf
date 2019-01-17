# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jchardin <jerome.chardin@outlook.com>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/14 15:34:59 by jchardin          #+#    #+#              #
#    Updated: 2019/01/17 16:30:05 by llejeune         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = exe_printf

SRC = file_util.c  ft_printf.c  ft_itoa_base.c  ft_utoa.c

OBJ = $(SRC:.c=.o)

SRC_Dir = ./srcs/
OBJ_Dir = ./obj/
CSources=$(addprefix $(SRC_Dir),$(SRC))
CObjects=$(addprefix $(OBJ_Dir),$(OBJ))

CFLAGS = -Wall -Wextra -Werror

CC = cc -g

$(NAME): $(CObjects)
	make -C ./libft
	cc -g   $(CObjects)  libft/libft.a -o $(NAME)
	

$(OBJ_Dir)%.o:$(SRC_Dir)%.c 
	mkdir $(OBJ_Dir) 2> /dev/null || true
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	/bin/rm -rf $(CObjects)
	make fclean -C ./libft

fclean: clean
	/bin/rm -rf $(NAME)

re: fclean $(NAME)

me: re
#	norminette includes/ft_printf.h ./srcs
#	ctags -R

.PHONY: all clean fclean re
