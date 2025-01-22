#include "../include/list.h"

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
