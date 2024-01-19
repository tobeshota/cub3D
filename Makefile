NAME			= cub3D

MAIN_SRC		= main.c
CHECK_SRC		= check_set_texture_path.c  check_set_map.c check_input_texture_path.c check_rgb_value.c
INIT_SRC		= init_map.c input.c input_texture.c input_map.c set_map.c set_texture_path.c
UTILS_SRC		= str_related.c length.c judge.c free.c
ERROR_SRC		= error.c

SRCDIR			= srcs
SRCS			= $(addprefix $(SRCDIR)/main/, $(MAIN_SRC))
SRCS			+= $(addprefix $(SRCDIR)/check/, $(CHECK_SRC))
SRCS			+= $(addprefix $(SRCDIR)/init/, $(INIT_SRC))
SRCS			+= $(addprefix $(SRCDIR)/utils/, $(UTILS_SRC))
SRCS			+= $(addprefix $(SRCDIR)/error/, $(ERROR_SRC))

MAKE_DIR		= main init check utils error

OBJDIR = objs
OBJS = $(subst $(SRCDIR), $(OBJDIR), $(SRCS:.c=.o))
DEPS = $(OBJS:.o=.d)
MAKE_DIRS = $(addprefix $(OBJDIR)/, $(MAKE_DIR))

CFLAGS = -Wall -Wextra -Werror -MP -MMD -O3
RM = rm -rf

INC = -I./inc/ -I./libft/inc -I./minilibx-linux

LIBFT = libft/libft.a

ifeq ($(MAKECMDGOALS), address)
	CFLAGS += -g3 -fsanitize=address
endif

CHECK		= \033[32m[✔]\033[0m
REMOVE		= \033[31m[✘]\033[0m
GENERATE	= \033[33m[➤]\033[0m
BLUE		= \033[1;34m
YELLOW		= \033[1;33m
RESET		= \033[0m

TOTAL_FILES := $(shell echo $(words $(SRCS)))
CURRENT_FILE = 1

define progress
    @printf "$(GENERATE) $(YELLOW)Cub3d obj file gen Progress: %3d%% (%d/%d)$(RESET)\r" $$(($(CURRENT_FILE)*100/$(TOTAL_FILES))) $(CURRENT_FILE) $(TOTAL_FILES)
    @$(eval CURRENT_FILE=$(shell echo $$(($(CURRENT_FILE)+1))))
    @if [ $(CURRENT_FILE) -gt $(TOTAL_FILES) ]; then \
        printf "$(GENERATE) $(YELLOW)Finish Generating CUB3D Object files !%-50.50s\n$(RESET)"; \
    fi
endef

all : $(NAME)

$(NAME): $(CCMLX) $(OBJS)
	@ $(MAKE) -s -C ./libft
	@ $(CC) $(CFLAGS) -o $@ $^ $(LIBFT)
	@ printf "$(CHECK) $(BLUE)Compiling cub3D...%-50.50s\n$(RESET)"

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@ mkdir -p $(MAKE_DIRS)
	@ $(CC) $(CFLAGS) $(INC) -o $@ -c $<
	$(call progress)

$(CCMLX):
	@ -git clone https://github.com/42Paris/minilibx-linux.git 2>/dev/null
	@ $(MAKE) -s -C ./minilibx-linux 2>/dev/null

clean :
	@ $(MAKE) -s -C ./libft clean
	@ $(MAKE) -s -C ./minilibx-linux clean
	@ $(RM) $(OBJDIR)
	@ echo "$(REMOVE) $(BLUE)Remove cub3D object files. $(RESET)"

fclean :
	@ $(MAKE) -s -C ./libft fclean
	@ $(MAKE) -s -C ./minilibx-linux clean
	@ $(RM) $(OBJDIR) $(NAME)
	@ echo "$(REMOVE) $(BLUE)Remove cub3D object files and $(NAME). $(RESET)"

re : fclean all

address : re

norm :
	norminette srcs includes libft

.PHONY : all clean fclean re norm address

-include $(DEPS)
