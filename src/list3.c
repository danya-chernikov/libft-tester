#include "../include/list.h"

void	add_list_tests(t_lst_test *tests)
{
	strncpy(tests->strs[0], "just some text", MAX_TEST_STR_LEN);
	tests->ints[0] = 10;
	tests->floats[0] = 5.6;
	tests->chars[0] = 'X';
	tests->shorts[0] = -512;
}

/* This is the main function that manages all
 * the test logic */
void	test_linked_list_1(t_lst_test *tests)
{
	t_cnt_type	types[MAX_LST_NODES_NUM];
	t_list		*head_ptr;
	int			type_cnt;

	type_cnt = 0;
	types[type_cnt] = STRING;
	head_ptr = lstnew_test((char *)tests->strs[0], STRING);
	type_cnt++;

	print_list(head_ptr, types, 0);
	lstsize_test(&head_ptr);

	types[type_cnt] = INT;
	addfront_quick(&head_ptr, (int *)&(tests->ints[0]), INT);
	type_cnt++;

	print_list(head_ptr, types, 0);
	lstsize_test(&head_ptr);

	types[type_cnt] = FLOAT;
	addfront_quick(&head_ptr, (float *)&(tests->floats[0]), FLOAT);
	type_cnt++;

	print_list(head_ptr, types, 0);
	lstsize_test(&head_ptr);

	lstlast_test(head_ptr, STRING);

	types[type_cnt] = CHAR;
	addfront_quick(&head_ptr, (char *)&(tests->chars[0]), CHAR);
	type_cnt++;

	print_list(head_ptr, types, 0);
	lstsize_test(&head_ptr);

	addfront_test_type(types, type_cnt, SHORT);
	addback_quick(&head_ptr, (short *)&(tests->shorts[0]), SHORT);
	type_cnt++;

	print_list(head_ptr, types, 0);
	lstsize_test(&head_ptr);
}

void	addfront_quick(t_list **head_ptr, void *cnt, t_cnt_type type)
{
	t_list	*lst;

	lst = lstnew_test(cnt, type);
	lstadd_front_test(head_ptr, lst);
	*head_ptr = lst;
}

void	addback_quick(t_list **head_ptr, void *cnt, t_cnt_type type)
{
	t_list	*lst;

	lst = lstnew_test(cnt, type);
	lstadd_back_test(head_ptr, lst);
}
