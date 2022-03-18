# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <user42@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/09 11:32:21 by idouidi           #+#    #+#              #
#    Updated: 2021/10/06 13:27:52 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	srcs/main.c srcs/pipe/pipe.c srcs/pipe/utils_pipe.c srcs/redirection/redirection.c \
		srcs/pipex.c srcs/pipe/file_exist.c

LIBFTPATH	= project/libft 
LIBOBJ		= project/libft/libft.a
@OBJS		= $(SRCS:.c=.o)
CFLAGS		= -Wall -Wextra -Werror -g3 -fsanitize=address
NAME		= pipex

all: $(NAME)

$(NAME): $(@OBJS)
	@echo "\033[33m- Compiling libft..."
	$(MAKE) -C $(LIBFTPATH)
	@echo "\033[32mDone."
	@echo "\033[33m- Compiling pipex..."
	@gcc ${CFLAGS} -o ${NAME} ${@OBJS} $(LIBOBJ)
		@echo "\033[32mDone."
	@echo "\033[31m========================"
	@echo "  PIPEX IS READY"
	@echo "========================"

clean:
	rm -rf $(@OBJS)
	@cd $(LIBFTPATH) && make clean

fclean: clean
	@rm -f $(NAME)
	cd $(LIBFTPATH) && make fclean

re: fclean all


.PHONY: libft, all, clean, fclean, re
.SILENT: