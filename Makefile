SRCS         =	main.c \
				list_parsing.c \
				sort_big_stack.c \
				small_digit_transform.c \
				sort_small_stack.c\
				small_stack_movement.c\
				big_stack_movement.c\
				special_case_2_3.c\

OBJS         = ${SRCS:.c=.o}

NAME         = push_swap

AR             = ar rcs

GCC            = gcc

RM             = rm -f

CFLAGS         = -Wall -Wextra -Werror -g

LBFT_PATH    =     ./libft/

FRAMLIBS    =     -L ${LBFT_PATH} -lft -framework OpenGL -framework AppKit

all:         $(NAME)

.c.o:
			$(GCC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME):     $(OBJS)
			@$(MAKE) -C $(LBFT_PATH)
			$(GCC) $(OBJS) $(CFLAGS) -I ${LBFT_PATH} -o $(NAME) $(FRAMLIBS)

re:	fclean $(NAME)

clean:
			${RM} ${OBJS}
			@$(MAKE) -C $(LBFT_PATH) clean

fclean:     clean
			${RM} ${NAME}
			@$(MAKE) -C $(LBFT_PATH) fclean