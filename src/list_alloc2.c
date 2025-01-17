#include "../include/list.h"

int	alloc_lst_test_uints(t_lst_test *tests)
{
	u_int	**uints_ptrs;
	u_int	*uints;
	int		i;

	uints = (u_int *)malloc(MAX_LST_NODES_NUM * sizeof (u_int));
	if (uints == NULL)
		return (ERROR);
	tests->uints = uints;
	uints_ptrs = (u_int **)malloc(MAX_LST_NODES_NUM * sizeof (u_int *));
	if (uints_ptrs == NULL)
	{
		free(tests->uints);
		return (ERROR);
	}
	tests->uints_ptrs = uints_ptrs;
	i = 0;
	while (i < MAX_LST_NODES_NUM)
	{
		tests->uints_ptrs[i] = NULL;
		i++;
	}
	return (SUCCESS);
}

int	alloc_lst_test_longs(t_lst_test *tests)
{
	long	**longs_ptrs;
	long	*longs;
	int		i;

	longs = (long *)malloc(MAX_LST_NODES_NUM * sizeof (long));
	if (longs == NULL)
		return (ERROR);
	tests->longs = longs;
	longs_ptrs = (long **)malloc(MAX_LST_NODES_NUM * sizeof (long *));
	if (longs_ptrs == NULL)
	{
		free(tests->longs);
		return (ERROR);
	}
	tests->longs_ptrs = longs_ptrs;
	i = 0;
	while (i < MAX_LST_NODES_NUM)
	{
		tests->longs_ptrs[i] = NULL;
		i++;
	}
	return (SUCCESS);
}

int	alloc_lst_test_ulongs(t_lst_test *tests)
{
	t_ul	**ulongs_ptrs;
	t_ul	*ulongs;
	int		i;

	ulongs = (t_ul *)malloc(MAX_LST_NODES_NUM * sizeof (t_ul));
	if (ulongs == NULL)
		return (ERROR);
	tests->ulongs = ulongs;
	ulongs_ptrs = (t_ul **)malloc(MAX_LST_NODES_NUM * sizeof (t_ul *));
	if (ulongs_ptrs == NULL)
	{
		free(tests->ulongs);
		return (ERROR);
	}
	tests->ulongs_ptrs = ulongs_ptrs;
	i = 0;
	while (i < MAX_LST_NODES_NUM)
	{
		tests->ulongs_ptrs[i] = NULL;
		i++;
	}
	return (SUCCESS);
}

int	alloc_lst_test_lls(t_lst_test *tests)
{
	t_ll	**lls_ptrs;
	t_ll	*lls;
	int		i;

	lls = (t_ll *)malloc(MAX_LST_NODES_NUM * sizeof (t_ll));
	if (lls == NULL)
		return (ERROR);
	tests->lls = lls;
	lls_ptrs = (t_ll **)malloc(MAX_LST_NODES_NUM * sizeof (t_ll *));
	if (lls_ptrs == NULL)
	{
		free(tests->lls);
		return (ERROR);
	}
	tests->lls_ptrs = lls_ptrs;
	i = 0;
	while (i < MAX_LST_NODES_NUM)
	{
		tests->lls_ptrs[i] = NULL;
		i++;
	}
	return (SUCCESS);
}

int	alloc_lst_test_ulls(t_lst_test *tests)
{	
	t_ull	**ulls_ptrs;
	t_ull	*ulls;
	int	i;

	ulls = (t_ull *)malloc(MAX_LST_NODES_NUM * sizeof (t_ull));
	if (ulls == NULL)
		return (ERROR);
	tests->ulls = ulls;
	ulls_ptrs = (t_ull **)malloc(MAX_LST_NODES_NUM * sizeof (t_ull *));
	if (ulls_ptrs == NULL)
	{
		free(tests->ulls);
		return (ERROR);
	}
	tests->ulls_ptrs = ulls_ptrs;
	i = 0;
	while (i < MAX_LST_NODES_NUM)
	{
		tests->ulls_ptrs[i] = NULL;
		i++;
	}
	return (SUCCESS);
}
