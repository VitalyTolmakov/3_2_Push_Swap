# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fheidi <fheidi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/15 19:48:18 by fheidi            #+#    #+#              #
#    Updated: 2022/03/19 19:54:25 by fheidi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	push_swap
NAME2			=	checker
DIRECTORY		=	./
OBJECTS			=	./bin
LIBFT			=	./libft

SRCS			=	functions/pa.c functions/pb.c functions/ra.c functions/rb.c functions/rr.c \
	functions/rra.c functions/rrb.c functions/rrr.c functions/sa.c functions/sb.c functions/ss.c \
	all_sorts.c index_processing.c stack_processing.c valid_checker.c lists_processing.c push_swap.c parse_fill.c

SRCS_BONUS		=	functions/pa.c functions/pb.c functions/ra.c functions/rb.c functions/rr.c \
			functions/rra.c functions/rrb.c functions/rrr.c functions/sa.c functions/sb.c \
			functions/ss.c index_processing.c stack_processing.c valid_checker.c  \
			lists_processing.c parse_fill.c checker.c gnl/get_next_line.c gnl/get_next_line_utils.c


OBJS			=	$(addprefix ${OBJECTS}/, $(SRCS:.c=.o))
OBJS_BONUS		=	$(addprefix ${OBJECTS}/, $(SRCS_BONUS:.c=.o))

CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror
LIBRARY			=	-L${LIBFT} -lft

${OBJECTS}/%.o: ${DIRECTORY}/%.c
	mkdir -p $(dir $@)
	${CC} ${CFLAGS} -o $@ -c $<

all: ${NAME}

${NAME}: ${OBJS}
	make -C ${LIBFT}
	${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIBRARY}

bonus: ${OBJS_BONUS}
	make -C ${LIBFT}
	${CC} ${CFLAGS} -o ${NAME2} ${OBJS_BONUS} ${LIBRARY}

clean:
	make -C ${LIBFT} clean
	rm -rf ${OBJECTS}

fclean: clean
	make -C ${LIBFT} fclean
	rm -f ${NAME} ${NAME2}

re: fclean all

.PHONY:	all clean fclean re
