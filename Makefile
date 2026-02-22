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

val:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --suppressions=$(CURDIR)/supp_extra.supp ./$(NAME)

val-gen:
	valgrind --leak-check=full --show-leak-kinds=all \
	--track-origins=yes --gen-suppressions=all \
	--log-file=valgrind_output.txt ./$(NAME)

run: re
	./$(NAME)

.PHONY: all clean fclean re run  val val-gen