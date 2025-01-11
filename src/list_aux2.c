#include "../include/list.h"

void	addfront_quick(t_list **head_ptr, void *cnt, t_cnt_type type)
{
	t_list	*lst;

	lst = lstnew_test(cnt, type);
	lstadd_front_test(head_ptr, lst);
	*head_ptr = lst;
}

/* It prints n tabs consecutively */
void	print_tabs(int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		printf("\t");
		i++;
	}
}

int	lstsize(t_list **lst)
{
	t_list	*nptr;
	int		size;

	size = 1;
	nptr = (*lst)->next;
	while (nptr != NULL)
	{
		nptr = nptr->next;
		size++;
	}
	return (size);
}

void	add_list_tests(t_lst_test *tests)
{
	strncpy(tests->strs[0], "just some text", MAX_TEST_STR_LEN);
	tests->ints[0] = 10;
	tests->floats[0] = 5.6;
}

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
	addfront_quick(&head_ptr, (float *)&(tests->floats[0]),  FLOAT);
	print_list(head_ptr, types, 0);
	lstsize_test(&head_ptr);
}
