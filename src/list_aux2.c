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

void	free_node(void *ptr)
{
	free(ptr);
}
