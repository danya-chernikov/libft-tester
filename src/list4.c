#include "../include/list.h"

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
