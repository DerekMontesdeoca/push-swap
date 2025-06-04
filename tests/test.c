#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "algo.h"
#include "intlist.h"
#include "mergesort.h"
#include "push_swap.h"
#include "map.h"
#include "array.h"
#include "split_insert.h"

static int	comp(int32_t a, int32_t b)
{
	if (a < b)
		return (-1);
	if (a > b)
		return (1);
	return 0;
}

void test_insert_sort_to_a()
{

}

void test_split_to_b()
{
	t_push_swap 	ps;
	int32_t			numbers[] = {1, 5, 4, 9, 8, 7, 6};
	size_t			numbers_size = 7;
	t_split_insert	si;
	int32_t			expected_lis_idx[] = {0, 1, 3};
	size_t			expected_lis_size = 3;
	int32_t			expected_b_idx[] = {5, 6, 2, 4};
	size_t			expected_b_size = 4;
	t_intlist_node	*ptr;

	assert(push_swap_make(&ps, numbers, numbers_size));
	assert(split_insert_make(&si, &ps));
	push_non_lis_to_b_and_pivot_split(&si);

	assert(expected_lis_size == si.lis.size);
	for (size_t i = 0; i < si.lis.size; ++i)
		assert(si.lis.arr[i] == expected_lis_idx[i]);

	assert(ps.b.len == expected_b_size);
	ptr = ps.b.head;
	for (size_t i = 0; i < ps.b.len; ++i)
	{
		assert(ptr->data == expected_b_idx[i]);
		ptr = ptr->next;
	}

	split_insert_destroy(&si);
	push_swap_destroy_contents(&ps);
}

void test_qsort()
{
	int32_t arr[] = {1,3,5,2,4,9};
	quicksort(arr, 6, comp);
	int32_t expected[] = {1,2,3,4,5,9};
	for (size_t i = 0; i < 6; ++i)
	{
		assert(expected[i] == arr[i]);
	}
}

void test_array_diff()
{
	t_int_array a = {.arr=(int32_t[]){1,2,3,4,5,4}, .size=6};
	t_int_array b = {.arr=(int32_t[]){1,4,2,3}, .size=4};
	t_map	result;
	int_array_diff(&a, &b, &result);
	t_int_array expected = {.arr=(int32_t[]){5,4}, 2};
	assert(expected.size == result.len);
	for (size_t i = 0; i < expected.size; ++i)
		assert(map_lookup(&result, expected.arr[i]) != NULL);
	map_destroy_contents(&result);
}

void test_lis()
{
	int32_t *arr = (int32_t[]){1, 2, 2, 3, 4, 4, 4, 4, 5};
	size_t size_out;
	int32_t *values;
	if (!lis(arr, 9, &values, &size_out))
		assert(false);
	int32_t *expected = (int32_t[]){1,2,3,4,5};
	for (size_t i = 0; i < 5; ++i)
	{
		assert(expected[i] == values[i]);
	}
	free(values);
}

void test_lis_2()
{
	int32_t *arr = (int32_t[]){5,3,9,8,3,2,7,11};
	size_t arr_size = 8;
	size_t size_out;
	int32_t *values;
	if (!lis(arr, arr_size, &values, &size_out))
		assert(false);
	int32_t *expected = (int32_t[]){2,7,11};
	size_t 	expected_size_out = 3;
	assert(size_out == expected_size_out);
	for (size_t i = 0; i < size_out; ++i)
	{
		assert(expected[i] == values[i]);
	}
	free(values);
}

void test_lower_bound()
{
	int32_t *arr = (int32_t[]){1, 2, 2, 3, 4, 4, 4, 4, 5};
	int32_t *value = lower_bound(arr, 9, 4);
	assert(value - arr == 4);
	arr = (int32_t[]){1, 2, 2, 3, 4, 4, 4, 4, 6};
	value = lower_bound(arr, 8, 2);
	assert(value - arr == 1);
	value = lower_bound(arr, 9, 5);
	assert(value - arr == 8);
	value = lower_bound(arr, 9, 15);
	assert(value - arr == 9);
}

void test_pushswap()
{
	t_push_swap ps;
	(void)ps;
	int32_t numbers[] = {3,4,2,1,9,8,7,10,15,0,-5};
	size_t len = sizeof(numbers) / sizeof(numbers[0]);
	if (!push_swap_make(&ps, numbers, len))
		assert(false);
	t_intlist_node	*ptr = ps.a.head;
	for (size_t i = 0; i < len; ++i)
	{
		assert(numbers[i] == ps.sorted_numbers[ptr->data]);
		ptr = ptr->next;
	}
	push_swap_destroy_contents(&ps);
}

void test_map()
{
	t_map	map;

	assert(map_make(&map, 5));
	int32_t numbers[] = {1, 2, 4, 9 ,3};
	for (size_t i = 0; i < 5; ++i) 
		map_insert(&map, numbers[i], numbers[i]);
	int32_t *value;
	for (size_t i = 0; i < 5; ++i) 
	{
		assert((value = map_lookup(&map, numbers[i])) != NULL);
		assert(*value == (int32_t) numbers[i]);
	}
	map_destroy_contents(&map);
}

void test_mergesort()
{
	int32_t arr[] = {5,3,2,4,9,1};
	int32_t dest[sizeof(arr)];
	int32_t expected[] = {1,2,3,4,5,9};
	mergesort(arr, dest, sizeof(arr) / sizeof(arr[0]));
	for (size_t i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
		assert(dest[i] == expected[i]);
}

void test_mergesort_1()
{
	int32_t arr[] = {5};
	int32_t dest[sizeof(arr)];
	int32_t expected[] = {5};
	mergesort(arr, dest, sizeof(arr) / sizeof(arr[0]));
	for (size_t i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
		assert(dest[i] == expected[i]);
}

void test_mergesort_empty()
{
	int32_t arr[] = {};
	int32_t dest[sizeof(arr)];
	int32_t expected[] = {};
	mergesort(arr, dest, sizeof(arr) / sizeof(arr[0]));
	for (size_t i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
		assert(dest[i] == expected[i]);
}

void test_intlist_insert()
{
	t_intlist_node nodes[5];
	t_intlist lst = {};

	for (int i = 0; i < 5; ++i)
	{
		intlist_node_make(&nodes[i], i);
		intlist_insert(&lst, &nodes[i]);
	}
	t_intlist_node *ptr = lst.head;
	for (int i = 0; i < 5; ++i)
	{
		assert(ptr->data == 4 - i);
		ptr = ptr->next;
	}
}

void	test_intlist_operations()
{
	t_intlist_node nodes[5];
	t_intlist lst = {};

	for (int i = 0; i < 5; ++i)
	{
		intlist_node_make(&nodes[i], i);
		intlist_insert(&lst, &nodes[i]);
	}

	assert(lst.head->data == 4);

	intlist_swap(&lst);
	assert(lst.head->data == 3);

	intlist_rotate(&lst);
	assert(lst.head->data == 4);

	intlist_rotate(&lst);
	assert(lst.head->data == 2);

	intlist_rrotate(&lst);
	assert(lst.head->data == 4);

	t_intlist_node *removed = intlist_pop(&lst);
	assert(removed->data == 4);
	assert(lst.len == 4);
	assert(lst.head->data == 2);

	intlist_rrotate(&lst);
	assert(lst.head->data == 3);

	for (int i = 0; i < 4; ++i)
		intlist_rrotate(&lst);
	assert(lst.head->data == 3);

	for (int i = 0; i < 4; ++i)
		intlist_rotate(&lst);
	assert(lst.head->data == 3);

	for (int i = 0; i < 4; ++i)
		intlist_pop(&lst);
	assert(lst.head == NULL);
	assert(lst.len == 0);
}

int main()
{
	test_intlist_insert();
	test_intlist_operations();
	test_mergesort();
	test_mergesort_1();
	test_mergesort_empty();
	test_map();
	test_pushswap();
	test_lower_bound();
	test_lis();
	test_lis_2();
	test_array_diff();
	test_qsort();
	test_split_insert();
	return (0);
}
