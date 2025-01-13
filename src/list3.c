#include "../include/list.h"

/* This is the main function that manages all
 * the test logic */
void	linked_list_launch_tests(t_lst_test *tests)
{
	t_lst_d	*list;

	list = list_debug_init((char *)tests->strs[0], STRING);
	if (list == NULL)
		return ;
	addfront_quick(list, (int *)&(tests->ints[0]), INT);
	addfront_quick(list, (float *)&(tests->floats[0]), FLOAT);
	lstlast_test(list->head, STRING);
	addfront_quick(list, (char *)&(tests->chars[0]), CHAR);
	addback_quick(list, (short *)&(tests->shorts[0]), SHORT);
	lstlast_test(list->head, SHORT);
	free_list_debug(list);
}

void	add_list_tests(t_lst_test *tests)
{
	strncpy(tests->strs[0], "just some text", MAX_TEST_STR_LEN);
	tests->ints[0] = 10;
	tests->floats[0] = 5.6;
	tests->chars[0] = 'X';
	tests->shorts[0] = -512;
}

/* It creates a new singly linked list, allocates memory for an
 * array of all possible node content types, and initializes the
 * list by adding the first node with content `cnt` of `type` type */
t_lst_d	*list_debug_init(void *cnt, t_cnt_type type)
{
	t_lst_d	*list;

	list = (t_lst_d *)malloc(1 * sizeof (t_lst_d));
	if (list == NULL)
		return (NULL);
	list->type_cnt = 0;
	list->types = (t_cnt_type *)malloc(MAX_LST_NODES_NUM * sizeof (t_cnt_type));
	if (list->types == NULL)
		return (NULL);
	list->types[list->type_cnt] = type;
	list->head = lstnew_test(cnt, type);
	list->type_cnt++;
	print_list(list, 0);
	lstsize_test(&list->head);
	return (list);
}

void	addfront_quick(t_lst_d *list, void *cnt, t_cnt_type type)
{
	t_list	*lst;

	list->types[list->type_cnt] = type;
	lst = lstnew_test(cnt, type);
	lstadd_front_test(&list->head, lst);
	list->head = lst;
	list->type_cnt++;
	print_list(list, 0);
	lstsize_test(&list->head);
}

void	addback_quick(t_lst_d *list, void *cnt, t_cnt_type type)
{
	t_list	*lst;

	addfront_test_type(list->types, list->type_cnt, type);
	lst = lstnew_test(cnt, type);
	lstadd_back_test(&list->head, lst);
	list->type_cnt++;
	print_list(list, 0);
	lstsize_test(&list->head);
}
