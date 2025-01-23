#include "../include/list.h"

/* It creates a new singly linked list, allocates
 * memory for an array of all possible node content
 * types, and initializes the list by adding the
 * first node with content `cnt` of `type` type */
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

void	init_list_tests(t_lst_test *tests)
{
	tests->nodes_num_to_free = 0;
	init_static_list_tests(tests);
	init_heap_list_tests(tests);
}

void	init_static_list_tests(t_lst_test *tests)
{
	tests->chars = NULL;
	tests->uchars = NULL;
	tests->shorts = NULL;
	tests->ushorts = NULL;
	tests->ints = NULL;
	tests->uints = NULL;
	tests->longs = NULL;
	tests->ulongs = NULL;
	tests->lls = NULL;
	tests->ulls = NULL;
	tests->floats = NULL;
	tests->doubles = NULL;
	tests->ldoubles = NULL;
	tests->strs = NULL;
	tests->voids = NULL;
}

void	init_heap_list_tests(t_lst_test *tests)
{
	tests->chars_ptrs = NULL;
	tests->uchars_ptrs = NULL;
	tests->shorts_ptrs = NULL;
	tests->ushorts_ptrs = NULL;
	tests->ints_ptrs = NULL;
	tests->uints_ptrs = NULL;
	tests->longs_ptrs = NULL;
	tests->ulongs_ptrs = NULL;
	tests->lls_ptrs = NULL;
	tests->ulls_ptrs = NULL;
	tests->floats_ptrs = NULL;
	tests->dbls_ptrs = NULL;
	tests->ldbls_ptrs = NULL;
	tests->strs_ptrs = NULL;
	tests->voids_ptrs = NULL;
}
