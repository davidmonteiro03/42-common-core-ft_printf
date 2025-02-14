# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/06 10:17:28 by dcaetano          #+#    #+#              #
#    Updated: 2025/02/14 11:01:58 by dcaetano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME   = libftprintf.a
SRCS   = ft_printf.c ft_putchar.c ft_putstr.c ft_putptr.c ft_putnbr.c \
         ft_putnbr_base.c ft_format.c
OBJS   = $(SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror
CC     = cc

all: $(NAME)

$(OBJS): %.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@make -sC libft
	@cp libft/libft.a $(NAME)
	@ar rcs $(NAME) $(OBJS)
	@ranlib $(NAME)

clean:
	@make -sC libft clean
	@rm -rf $(OBJS)

fclean: clean
	@make -sC libft fclean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
