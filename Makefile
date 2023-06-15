NAME = philo
FILE  = philo \
		utils \
		init \
		ft_time \
		errors \
		checker \
		launcher

SRC = $(foreach f, $(FILE), srcs/$(f).c)
OBJ = $(SRC:.c=.o)

CFLAGS = -Iheaders -fsanitize=address -g

all: $(NAME)
r: all
	./philo 4 410 200 200

$(NAME): $(OBJ)
	@printf "\x1b[32mAll objects compiled\x1b[0m\n"
	@gcc -o $(NAME) srcs/main.c $(OBJ) $(CFLAGS)
	@printf "\x1b[32mExecutable compiled\x1b[0m\n"

.c.o:
	@gcc $(CFLAGS) -o $@ -c $<

clean:
	@rm -rf $(OBJ) srcs/main.o
	@printf "\x1b[32mAll objects cleaned\x1b[0m\n"

fclean: clean
	@rm -rf $(LIB) $(NAME)
	@printf "\x1b[32mExecutable and library cleaned\x1b[0m\n"

re: fclean all

.PHONY: all bonus clean fclean re