#include "../include/list.h"

/* This is the main function that manages all
 * the test logic */
void	test_linked_list_1(t_lst_test *tests)
{
	t_list_debug	*list;

	list = list_debug_init((char *)tests->strs[0], STRING);
	if (list == NULL)
		return ;
	addfront_quick(list, (int *)&(tests->ints[0]), INT);
	addfront_quick(list, (float *)&(tests->floats[0]), FLOAT);
	lstlast_test(list->head, STRING);
	addfront_quick(list, (char *)&(tests->chars[0]), CHAR);
	addback_quick(list, (short *)&(tests->shorts[0]), SHORT);
	list_debug_free(list);
}

/* It creates a new singly linked list, allocates memory for an
 * array of all possible node content types, and initializes the
 * list by adding the first node with content `cnt` of `type` type */
t_list_debug	*list_debug_init(void *cnt, t_cnt_type type)
{
	t_list_debug	*list;

	list = (t_list_debug *)malloc(1 * sizeof (t_list_debug));
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

void	addfront_quick(t_list_debug *list, void *cnt, t_cnt_type type)
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

void	addback_quick(t_list_debug *list, void *cnt, t_cnt_type type)
{
	t_list	*lst;

	addfront_test_type(list->types, list->type_cnt, type);
	lst = lstnew_test(cnt, type);
	lstadd_back_test(&list->head, lst);
	list->type_cnt++;
	print_list(list, 0);
	lstsize_test(&list->head);
}

void	list_debug_free(t_list_debug *list)
{
	free(list->types);
	free(list);
}
