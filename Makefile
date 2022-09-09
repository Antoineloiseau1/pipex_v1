# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anloisea <anloisea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/06 15:25:26 by anloisea          #+#    #+#              #
#    Updated: 2022/09/09 16:59:58 by anloisea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	pipex

SRCS 	= 	./srcs/pipex.c ./srcs/get_paths.c ./srcs/check_path.c

OBJS	=	${SRCS:.c=.o}

CFLAGS	= 	-Wall -Werror -Wextra

LIB		=	libft/libft.a

LPATH	= 	./libft

all:		${LIB} ${NAME}

${LIB}:		
			@make all -C ${LPATH}

${NAME}:	${OBJS}
			gcc ${CFLAGS} ${OBJS} -L./libft/ -lft -o ${NAME}

clean:
			@make clean -C ${LPATH}
			rm -rf ${OBJS}

fclean:		clean
			@make fclean -C ${LPATH}
			rm -rf ${OBJS} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re




