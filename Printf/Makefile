# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hchalaby <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/19 17:17:32 by hchalaby          #+#    #+#              #
#    Updated: 2023/02/19 17:17:34 by hchalaby         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFTNAME = libft.a
LIBFTDIR = ./LIBFT

CFLAGS = -Wall -Werror -Wextra

SRC = ft_printchar.c ft_printf.c ft_printhex.c ft_printint.c ft_printpointer.c \
		ft_printstring.c ft_printunsig.c

OBJ = $(SRC:.c=.o)


CC = cc

all: $(NAME)

makelibft:
	@make -C $(LIBFTDIR)
	@cp $(LIBFTDIR)/$(LIBFTNAME) .
	@mv $(LIBFTNAME) $(NAME)

%.o:%.c 
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): makelibft $(OBJ)
	@ar rcs $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)
	@cd $(LIBFTDIR) &&  make clean

fclean: clean
	@rm -f $(NAME) $(OBJ)
	@cd $(LIBFTDIR) && make fclean

re: fclean all

.PHONY: all clean fclean re
 