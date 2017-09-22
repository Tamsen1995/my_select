CC = gcc
FLAGS = -g -Wall -Wextra -Werror -I includes
LIBFT = libft/libft.a
NAME = ft_select
SRC = src/main.c \
	src/shell_ops.c \
	src/handlers.c \
	src/params/init_params.c \
	src/params/add_brackets.c \
	src/params/out_params.c \
	src/helpers/find_max_str.c \
	src/helpers/words_per_line.c \
	src/input/handle_input.c \
	src/input/cursors.c \

OBJ = $(addsuffix .o, $(basename $(SRC)))

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C libft

$(NAME):$(LIBFT) $(NAME) $(OBJ)
	@echo "building binary file"
	$(CC) $(FLAGS) $(SRC) -o $(NAME) -I -lft $(LIBFT) -ltermcap

%.o: %.c ft_select.h
		clang $(FLAG) -c $< -o  $@

clean:
	rm -f $(OBJ)
	@make clean -C libft/

fclean: clean
	@echo "delete $(NAME)"
	@rm -f $(NAME)
	@make fclean -C libft/

re: fclean all

.PHONY: re clean fclean all