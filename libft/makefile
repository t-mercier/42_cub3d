CFLAGS += -Wall -Wextra -Werror
NAME = libft.a
OUT = out/
SRCS = ft_calloc.c ft_is1.c ft_is2.c ft_list1.c ft_list2.c ft_mem.c \
 ft_misc.c ft_put.c ft_str.c ft_str2.c ft_str3.c ft_str4.c ft_to.c \
 ft_to2.c args.c args2.c q1.c q2.c time.c verify.c \
 v.c v2.c v3.c v4.c v5.c v6.c l1.c l2.c \
 ft_printf.c ft_printf_util.c ft_printf_a.c ft_printf2.c \
 get_next_line.c get_next_line_utils.c \

OBJS = $(addprefix $(OUT),$(SRCS:.c=.o))

all: $(NAME)

$(OUT)%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar crs $(NAME) $(OBJS)

bonus: $(NAME)

clean:
	rm -rf $(OUT)

fclean:
	rm -rf $(OUT) '$(NAME)'

re: fclean all
