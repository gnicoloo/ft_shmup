NAME = ft_shmup
SRCS = src/*.cpp
INCLUDES = includes/

all: $(NAME)

$(NAME):
	g++ src/*.cpp -Iincludes -I/mingw64/include/ncursesw -o build/ft_shmup -lncursesw

fclean:
	@-rm -f build/*

run: all
	./run

.PHONY: fclean all