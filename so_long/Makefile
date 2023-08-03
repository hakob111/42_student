# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hchalaby <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/04 14:21:57 by hchalaby          #+#    #+#              #
#    Updated: 2023/07/04 14:22:02 by hchalaby         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
LIBFTNAME = libft.a
LIBFTDIR = ./LIBFT
PRINTFNAME = libftprintf.a
PRINTFDIR = ./PRINTF

CFLAGS = -Wall -Werror -Wextra #-g3 -fsanitize=address

GNL = get_next_line.c get_next_line_utils.c
GNL_SRC = $(addprefix get_next_line/, $(GNL))

MAP = check.c check_ber.c err_exit.c
MAP_SRC = $(addprefix maps/, $(MAP))

RENDER = render.c keypress.c key_logic.c animation.c exit_game.c
RENDER_SRC = $(addprefix render/, $(RENDER))


MY_SRC = so_long.c

SRC = $(MY_SRC) $(GNL_SRC) $(MAP_SRC) $(RENDER_SRC)

OBJ = $(SRC:.c=.o)

HEADERS = $(wildcard get_next_line/get_next_line.h) $(wildcard Libft/libft.h) $(wildcard Printf/ft_printf.h) $(wildcard so_long.h) $(wildcard render/render.h)

CC = cc

all:  makelibftprintf $(OBJ) $(NAME)

makelibft:
	@make -C $(LIBFTDIR)

makelibftprintf:
	@make -C $(PRINTFDIR)

%.o:%.c $(HEADERS) Makefile
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME): $(OBJ) $(HEADERS) Makefile
	cc $(CFLAGS) $(OBJ) -LPrintf -lftprintf -Llibft -lft -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	@rm -f $(OBJ)
	@cd $(LIBFTDIR) &&  make clean

fclean: clean
	@rm -f $(NAME) $(OBJ)
	@cd $(LIBFTDIR) && make fclean

re: fclean all

.PHONY: all clean fclean re
