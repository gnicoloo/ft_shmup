NAME = ft_shmup
SRCS = src/*.cpp
INCLUDES = includes/

all: $(NAME)

$(NAME):
	g++ $(SRCS) -Iincludes -o build/$(NAME) -lncurses

fclean:
	@-rm -f build/*

run: all
	./run

.PHONY: fclean all