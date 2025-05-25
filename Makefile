CC := cc
NAME := push_swap
HEADERS := push_swap.h
SRCS := main.c stack.c push_swap.c stacks.c algo1.c
LIBFT := libft/libft.a
LDFLAGS := 
CFLAGS := -Wall -Wextra -Werror
CPPFLAGS := -Ilibft/include


OBJS := $(SRCS:.c=.o)
ifeq ($(DEBUG), 1)
	CFLAGS += -g3
endif

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(LDFLAGS) -o $@ $^

$(LIBFT):
	$(MAKE) -C $$(dirname $(LIBFT))

%.o: %.c $(HEADERS)
	cc $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS)
	$(MAKE) -C libft clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C libft fclean


.PHONY: fclean clean all
