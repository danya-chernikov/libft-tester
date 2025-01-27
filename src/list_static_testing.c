#include "../include/list.h"

/* It performs static testing of a singly linked list,
 * i.e., this function launches predefined tests that
 * can be easily hardcoded into its body, by the way */
void	linked_list_launch_static_testing(t_lst_test *tests)
{
	t_lst_d	*list;
	t_list	*node;

	list = list_debug_init((char *)tests->strs_ptrs[0], STRING, true);
	if (list == NULL)
		return ;
	addfront_quick(list, (int *)tests->ints_ptrs[0], INT, true);
	addfront_quick(list, (float *)tests->floats_ptrs[0], FLOAT, true);
	lstlast_test(list->head, STRING); // Improve it! The caller does not need to know the content type of the last node!
	addfront_quick(list, (char *)tests->chars_ptrs[0], CHAR, true);
	addback_quick(list, (short *)tests->shorts_ptrs[0], SHORT, true);
	lstlast_test(list->head, SHORT); // Improve it!
	addback_quick(list, (long *)tests->longs_ptrs[0], LONG, true);
	addback_quick(list, (int *)tests->ints_ptrs[1], INT, true);
	node = get_node(list, 4);
	if (node != NULL)
		lstclear_test(list, &node, del, tests);
	print_list(list, 0);
	lstsize_test(&list->head);
	free_list_debug(list);
}

void	add_static_list_tests(t_lst_test *tests)
{
	tests->strs_ptrs[0] = alloc_string("just some text");
	tests->ints_ptrs[0] = alloc_int(10);
	tests->floats_ptrs[0] = alloc_float(5.6);
	tests->chars_ptrs[0] = alloc_char('X');
	tests->shorts_ptrs[0] = alloc_short(-512);
	tests->longs_ptrs[0] = alloc_long(1340802489);
	tests->ints_ptrs[1] = alloc_int(948010);
}
