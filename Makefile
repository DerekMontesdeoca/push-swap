CC := cc
NAME := push_swap


MODULES := push_swap.h \
		   solution.h solution_internal.h

LIB_MODULES := algo.h array.h circular_distances.h cmp.h intlist.h map.h

HEADERS := $(MODULES) $(LIB_MODULES)

SRCS := array.c binary_search.c circular_distances.c circular_lis.c cmp.c \
		hash.c insert_plan.c insert_plan_make.c int32_t_cmp.c intlist.c \
		intlist_node.c intlist_index.c lis.c main.c map.c \
		map_from_array.c mergesort.c op.c op_vector.c push_swap.c \
		push_swap_print.c push_swap_push.c push_swap_rotate.c \
		push_swap_rrotate.c push_swap_swap.c quicksort.c solution.c \
		split_insert.c push_swap_print_ops.c op_vector_destroy.c

LIBFT := libft/libft.a
LDFLAGS := 
CFLAGS := -Wall -Wextra -Werror
CPPFLAGS := -Ilibft/include

OBJS := $(SRCS:.c=.o)

################################################################################
# Don't edit past this point 
################################################################################

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
