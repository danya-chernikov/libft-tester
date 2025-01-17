#include "../include/list.h"
#include "../include/putsmth_fd.h"
/* We included `putsmth_fd.h` to use
 * the `form_common_err_msg()` function */

/* This is the main function that launches all the tests */
void	linked_list_launch_tests(t_lst_test *tests)
{
	t_lst_d	*list;
	t_list	*node;

	list = list_debug_init((char *)tests->strs_ptrs[0], STRING);
	if (list == NULL)
		return ;
	addfront_quick(list, (int *)tests->ints_ptrs[0], INT);
	addfront_quick(list, (float *)tests->floats_ptrs[0], FLOAT);
	lstlast_test(list->head, STRING);
	addfront_quick(list, (char *)tests->chars_ptrs[0], CHAR);
	addback_quick(list, (short *)tests->shorts_ptrs[0], SHORT);
	lstlast_test(list->head, SHORT);
	addback_quick(list, (long *)tests->longs_ptrs[0], LONG);
	addback_quick(list, (int *)tests->ints_ptrs[1], INT);
	node = get_node(list, 6);
	printf("node = %p\n", node);
	lstclear_test(&node, del);
	tests->ints_ptrs[1] = NULL;
	free_list_debug(list);
}

int	create_list_tests(t_lst_test *tests)
{
	char	fname[MAX_FUNC_NAME_LEN];
	char	errbuf[MAX_ERR_BUF_SIZE];

	strncpy(fname, "create_list_tests", MAX_FUNC_NAME_LEN);
	init_list_tests(tests);
	if ((alloc_lst_test_strings(tests) == ERROR)
		|| (alloc_lst_test_ints(tests) == ERROR)
		|| (alloc_lst_test_floats(tests) == ERROR)
		|| (alloc_lst_test_chars(tests) == ERROR)
		|| (alloc_lst_test_shorts(tests) == ERROR)
		|| (alloc_lst_test_longs(tests) == ERROR))
	{
		form_common_err_msg(errbuf, fname, MEM_ERR_MSG);
		perror(errbuf);
		return (ERROR);
	}
	add_list_tests(tests);
	return (SUCCESS);
}

void	add_list_tests(t_lst_test *tests)
{
	tests->strs_ptrs[0] = alloc_string("just some text");
	tests->ints_ptrs[0] = alloc_int(10);
	tests->floats_ptrs[0] = alloc_float(5.6);
	tests->chars_ptrs[0] = alloc_char('X');
	tests->shorts_ptrs[0] = alloc_short(-512);
	tests->longs_ptrs[0] = alloc_long(1340802489);
	tests->ints_ptrs[1] = alloc_int(948010);
}

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

/* It inserts the `type` type at the beginning of the `types` array, which had
 * previously shifted all other elements to the right */
void	addfront_test_type(t_cnt_type *types, int type_cnt, t_cnt_type type)
{
	int	i;

	i = type_cnt;
	while (i > 0)
	{
		types[i] = types[i - 1];
		i--;
	}
	types[0] = type;
}
