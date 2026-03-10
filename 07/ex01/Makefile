CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = iter
SRC = src/main.cpp
OBJ = obj/main.o
INCLUDES = -Iinclude

all: $(NAME)

obj:
	@mkdir -p obj

$(OBJ): src/main.cpp | obj
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $^ -o $@

clean:
	rm -rf obj

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
