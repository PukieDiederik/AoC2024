## File stuff
SHELL		=	/bin/zsh

BUILD_DIR	= ./build
## Compilation

CXX			= c++
CXXFLAGS	= -Wall -Werror -Wextra

## Other
RM				= rm -rf
MAKE			= make -s

ECHO			= echo -e


# Colors
BLACK		= \033[0;30m
RED			= \033[0;31m
GREEN		= \033[0;32m
ORANGE		= \033[0;33m
BLUE		= \033[0;34m
PURPLE		= \033[0;35m
CYAN		= \033[0;36m
GRAY		= \033[0;37m
WHITE		= \033[0;38m
RESET		= \033[0m

# Targets
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

% : %.cpp | $(BUILD_DIR)
	@$(CXX) $< -o $(BUILD_DIR)/$@