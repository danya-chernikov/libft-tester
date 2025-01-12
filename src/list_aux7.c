#include "../include/list.h"

void	test_linked_list_1(t_lst_test *tests)
{
	t_cnt_type	types[MAX_LST_NODES_NUM];
	t_list		*head_ptr;

	types[0] = STRING;
	head_ptr = lstnew_test((char *)tests->strs[0], STRING);
	print_list(head_ptr, types, 0);
	lstsize_test(&head_ptr);
	types[1] = INT;
	addfront_quick(&head_ptr, (int *)&(tests->ints[0]), INT);
	print_list(head_ptr, types, 0);
	lstsize_test(&head_ptr);
	types[2] = FLOAT;
	addfront_quick(&head_ptr, (float *)&(tests->floats[0]), FLOAT);
	print_list(head_ptr, types, 0);
	lstsize_test(&head_ptr);
}
