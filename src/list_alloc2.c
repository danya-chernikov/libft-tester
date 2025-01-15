#include "../include/list.h"

int	alloc_lst_test_uints(t_lst_test *tests)
{
	int	i;

	tests->uints = (u_int *)malloc(MAX_LST_NODES_NUM * sizeof (u_int));
	if (tests->uints == NULL)
		return (0);
	tests->uints_ptrs = (u_int **)malloc(MAX_LST_NODES_NUM * sizeof (u_int *));
	if (tests->uints_ptrs == NULL)
	{
		free(tests->uints);
		return (0);
	}
	i = 0;
	while (i < MAX_LST_NODES_NUM)
	{
		tests->uints_ptrs[i] = NULL;
		i++;
	}
	return (1);
}

int	alloc_lst_test_longs(t_lst_test *tests)
{
	int	i;

	tests->longs = (long *)malloc(MAX_LST_NODES_NUM * sizeof (long));
	if (tests->longs == NULL)
		return (0);
	tests->longs_ptrs = (long **)malloc(MAX_LST_NODES_NUM * sizeof (long *));
	if (tests->longs_ptrs == NULL)
	{
		free(tests->longs);
		return (0);
	}
	i = 0;
	while (i < MAX_LST_NODES_NUM)
	{
		tests->longs_ptrs[i] = NULL;
		i++;
	}
	return (1);
}

int	alloc_lst_test_ulongs(t_lst_test *tests)
{
	int	i;

	tests->ulongs = (t_ul *)malloc(MAX_LST_NODES_NUM * sizeof (t_ul));
	if (tests->ulongs == NULL)
		return (0);
	tests->ulongs_ptrs = (t_ul **)malloc(MAX_LST_NODES_NUM * sizeof (t_ul *));
	if (tests->ulongs_ptrs == NULL)
	{
		free(tests->ulongs);
		return (0);
	}
	i = 0;
	while (i < MAX_LST_NODES_NUM)
	{
		tests->ulongs_ptrs[i] = NULL;
		i++;
	}
	return (1);
}

int	alloc_lst_test_lls(t_lst_test *tests)
{
	int	i;

	tests->lls = (t_ll *)malloc(MAX_LST_NODES_NUM * sizeof (t_ll));
	if (tests->lls == NULL)
		return (0);
	tests->lls_ptrs = (t_ll **)malloc(MAX_LST_NODES_NUM * sizeof (t_ll *));
	if (tests->lls_ptrs == NULL)
	{
		free(tests->lls);
		return (0);
	}
	i = 0;
	while (i < MAX_LST_NODES_NUM)
	{
		tests->lls_ptrs[i] = NULL;
		i++;
	}
	return (1);
}

int	alloc_lst_test_ulls(t_lst_test *tests)
{
	int	i;

	tests->ulls = (t_ull *)malloc(MAX_LST_NODES_NUM * sizeof (t_ull));
	if (tests->ulls == NULL)
		return (0);
	tests->ulls_ptrs = (t_ull **)malloc(MAX_LST_NODES_NUM * sizeof (t_ull *));
	if (tests->ulls_ptrs == NULL)
	{
		free(tests->ulls);
		return (0);
	}
	i = 0;
	while (i < MAX_LST_NODES_NUM)
	{
		tests->ulls_ptrs[i] = NULL;
		i++;
	}
	return (1);
}
