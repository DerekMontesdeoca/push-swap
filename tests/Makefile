CC := cc
NAME := test
CFLAGS := -Wall -Wextra -Werror -g3
CPPFLAGS := -I.. -I../libft/include
SRCS := test.c ../intlist.c ../intlist_node.c ../mergesort.c ../push_swap.c \
		../map.c ../push_swap_print.c ../binary_search.c ../lis.c ../array.c \
		../hash.c ../quicksort.c ../solution.c ../split_insert.c \
		../push_swap_push.c ../push_swap_swap.c ../push_swap_rotate.c \
		../push_swap_rrotate.c ../op_vector.c ../op.c ../lis.c \
		../circular_lis.c ../circular_distances.c ../cmp.c ../intlist_index.c \
		../insert_plan_make.c ../insert_plan.c ../int32_t_cmp.c
OBJS := $(SRCS:.c=.o)
HEADERS := ../intlist.h ../mergesort.h ../push_swap.h ../map.h ../algo.h \
		   ../array.h ../solution.h ../split_insert.h ../circular_distances.h \
		   ../ cmp.h ../insert_plan.h
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
