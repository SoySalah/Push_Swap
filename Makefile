NAME = push_swap

CC = cc

FLAGS = -Wall -Wextra -Werror

SRCS = ft_lstsize.c Push_A.c Push_B.c reverse.c Rreverse.c rotate.c Rrotate.c Sswap.c Swap.c \
		sort_3.c sort_4.c sort_5.c indexing.c push_front.c push_swap.c lets_parse.c im_checking.c \
		 free_func.c ft_split.c im_chunking.c free_stack.c

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean