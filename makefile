#--------------------------------------#
#               _      _____     _     #
#              | |    |____ |   | |    #
#     ___ _   _| |__      / / __| |    #
#    / __| | | | '_ \     \ \/ _` |    #
#   | (__| |_| | |_) |.___/ / (_| |    #
#    \___|\__,_|_.__/ \____/ \__,_|    #
#                                      #
#--------------------------------------#                               

BIN			=		cub3d
LIBFTDIR	=		libft
MLXDIR 		= 		MLX42
SRC			=		src

OS			:= 		$(shell uname -s)
LIBMLX		=		$(MLXDIR)/build/libmlx42.a
LIBFT		=		$(LIBFTDIR)/libft.a

SRCS		=		_main.c \
					check.c \
					drawline.c \
					gameinit.c \
					horizontal.c \
					keyhooks.c \
					minimap.c \
					parse.c \
					render.c \
					utils.c \
					vertical.c \
					walls.c

OBJS 		= 		$(addprefix out/,$(SRCS:.c=.o))

CFLAGS      +=		-I$(LIBFTDIR) -I$(MLXDIR)/include/MLX42

ifeq ($(OS),Linux)
LFLAGS 		= -lglfw -lm -framework Cocoa -framework OpenGL -framework IOKit
else
LFLAGS		= -lglfw3 -lm -framework Cocoa -framework OpenGL -framework IOKit
endif

ifndef DEV
CFLAGS		+=		-Ofast -Wall -Wextra -Werror 
else
CFLAGS      +=		-g -fsanitize=address
endif

$(shell mkdir -p out)

all: $(BIN)
	@printf "$(GREEN)cub3d ✓\n$(RESET)"

$(BIN): $(OBJS) $(LIBMLX) $(LIBFT)
	@$(CC) $(CFLAGS) -o $@ $^ $(LFLAGS)

out/%.o: $(SRC)/%.c $(SRC)/cub3d.h
	@printf "$(GREEN)Compiling: $(RESET)$*.c\n"
	$(CC) $(CFLAGS) -c -o $@ $<

$(LIBMLX):
	@printf "$(GREEN)Building MLX ...\n$(RESET)"
	@cmake $(MLXDIR) -B $(MLXDIR)/build
	@make -C $(MLXDIR)/build
	@printf "$(GREEN)libmlx42.a ✓\n$(RESET)"

$(LIBFT): 
	@printf "$(GREEN)Building libft.a ...\n$(RESET)"
	$(MAKE) -C $(LIBFTDIR)

clean:
	$(MAKE) -C $(LIBFTDIR) clean
	rm -rf $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFTDIR) fclean
	rm -rf $(BIN)

re: fclean all

GREEN			:=	\033[1;32m
LIGHT_RED		:=	\033[1;31m
LIGHT_CYAN		:=	\033[1;36m
RESET			:= \033[0m

.PHONY: all clean fclean re
