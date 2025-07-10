CC := cc

CFLAGS := -Wall -Wextra -Werror

CPPFLAGS := -Ilibft/include

LDFLAGS := 

NAME := push_swap

MODULES := push_swap.h \
		   solution.h solution_internal.h

LIB_MODULES := algo.h array.h cmp.h intlist.h map.h

SRCS := array.c binary_search.c circular_distances.c circular_lis.c cmp.c \
		hash.c insert_plan.c insert_plan_make.c int32_t_cmp.c intlist.c \
		intlist_node.c intlist_index.c lis.c main.c map.c \
		map_from_array.c mergesort.c op.c op_vector.c push_swap.c \
		push_swap_print.c push_swap_push.c push_swap_rotate.c \
		push_swap_rrotate.c push_swap_swap.c quicksort.c solution.c \
		split_insert.c push_swap_print_ops.c op_vector_destroy.c \
		parse_numbers.c solution_insert_sort_a.c solution_easy_sort.c

LIBFT := libft/libft.a

BONUS := checker

BONUS_SRCS := checker.c solution_checker.c array.c binary_search.c \
			  cmp.c hash.c \
			  int32_t_cmp.c intlist.c intlist_node.c intlist_index.c lis.c \
			  map.c map_from_array.c mergesort.c op.c op_vector.c push_swap.c \
			  push_swap_print.c push_swap_push.c push_swap_rotate.c \
			  push_swap_rrotate.c push_swap_swap.c quicksort.c \
			  push_swap_print_ops.c op_vector_destroy.c \
			  parse_numbers.c 


BONUS_HEADERS := checker.h push_swap.h

################################################################################
# Don't edit past this point 
################################################################################

HEADERS := $(MODULES) $(LIB_MODULES)

OBJS := $(SRCS:.c=.o)

BONUS_OBJS := $(BONUS_SRCS:.c=.o)

ifeq ($(DEBUG), 1)
	CFLAGS += -g3
endif

all: $(NAME)

bonus: $(BONUS)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(LDFLAGS) -o $@ $^

$(BONUS): $(BONUS_OBJS) $(LIBFT)
	$(CC) $(LDFLAGS) -o $@ $^

$(LIBFT):
	$(MAKE) -C $$(dirname $(LIBFT))

%.o: %.c $(HEADERS)
	cc $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	$(MAKE) -C libft clean

fclean: clean
	rm -f $(NAME) $(BONUS)
	$(MAKE) -C libft fclean


.PHONY: fclean clean all
