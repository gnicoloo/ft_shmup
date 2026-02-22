NAME = build/ft_shmup
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror
INCLUDES = -Iincludes

SRC_DIR = src
BUILD_DIR = build

SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME) -lncurses

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	@-rm -f $(BUILD_DIR)/*.o

fclean: clean
	@-rm -f $(NAME)

re: fclean all

run: re
	./$(NAME)

.PHONY: all clean fclean re run