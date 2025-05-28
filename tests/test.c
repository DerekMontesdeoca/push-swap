#include <assert.h>
#include "intlist.h"

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
	intlist_rrotate(&lst);
	assert(removed->data == 0);
	assert(lst.len == 4);
	for (int i = 0; i < 4; ++i)
		intlist_rrotate(&lst);
	assert(lst.head->data == 0);
	for (int i = 0; i < 4; ++i)
		intlist_rotate(&lst);
	assert(lst.head->data == 0);
	for (int i = 0; i < 4; ++i)
		intlist_pop(&lst);
	assert(lst.head == NULL);
	assert(lst.len == 0);
}

int main()
{
	test_intlist_insert();
	return (0);
}
