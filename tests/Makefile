CC := cc
NAME := test
CFLAGS := -Wall -Wextra -Werror -g3
CPPFLAGS := -I.. -I../libft/include
SRCS := test.c ../intlist.c ../intlist_node.c
OBJS := $(SRCS:.c=.o)
HEADERS := ../intlist.h
LIBFT := ../libft/libft.a


all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) -o $@ $^

$(LIBFT): 
	$(MAKE) -C ../libft 

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

.PHONY: all clean fclean
