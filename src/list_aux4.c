#include "../include/list.h"

int	alloc_lst_test_ints(t_lst_test *tests)
{
	tests->ints = (int *)malloc(MAX_LST_NODES_NUM * sizeof (int));
	if (tests->ints == NULL)
		return (0);
	return (1);
}

int	alloc_lst_test_uints(t_lst_test *tests)
{
	tests->uints = (u_int *)malloc(MAX_LST_NODES_NUM * sizeof (u_int));
	if (tests->uints == NULL)
		return (0);
	return (1);
}

int	alloc_lst_test_longs(t_lst_test *tests)
{
	tests->longs = (long *)malloc(MAX_LST_NODES_NUM * sizeof (long));
	if (tests->longs == NULL)
		return (0);
	return (1);
}

int	alloc_lst_test_ulongs(t_lst_test *tests)
{
	tests->ulongs = (t_ul *)malloc(MAX_LST_NODES_NUM * sizeof (t_ul));
	if (tests->ulongs == NULL)
		return (0);
	return (1);
}

int	alloc_lst_test_lls(t_lst_test *tests)
{
	tests->lls = (long long *)malloc(MAX_LST_NODES_NUM * sizeof (long long));
	if (tests->lls == NULL)
		return (0);
	return (1);
}
