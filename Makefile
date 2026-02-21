NAME = ft_shmup

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror 

SRC = main.cpp Hub.cpp utils.cpp GameState.cpp 
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -lncurses -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

val:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --suppressions=$(CURDIR)/supp_extra.supp ./$(NAME)

val-gen:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --gen-suppressions=all ./$(NAME) > valgrind_output.txt

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re  val