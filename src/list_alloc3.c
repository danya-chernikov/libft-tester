#include "../include/list.h"

int	alloc_lst_test_floats(t_lst_test *tests)
{
	int	i;

	tests->floats = (float *)malloc(MAX_LST_NODES_NUM * sizeof (float));
	if (tests->floats == NULL)
		return (0);
	tests->floats_ptrs = (float **)malloc(MAX_LST_NODES_NUM * sizeof (float *));
	if (tests->floats_ptrs == NULL)
	{
		free(tests->floats);
		return (0);
	}
	i = 0;
	while (i < MAX_LST_NODES_NUM)
	{
		tests->floats_ptrs[i] = NULL;
		i++;
	}
	return (1);
}

int	alloc_lst_test_doulbes(t_lst_test *tests)
{
	int	i;

	tests->doubles = (double *)malloc(MAX_LST_NODES_NUM * sizeof (double));
	if (tests->doubles == NULL)
		return (0);
	tests->dbls_ptrs = (double **)malloc(MAX_LST_NODES_NUM * sizeof (double *));
	if (tests->dbls_ptrs == NULL)
	{
		free(tests->doubles);
		return (0);
	}
	i = 0;
	while (i < MAX_LST_NODES_NUM)
	{
		tests->dbls_ptrs[i] = NULL;
		i++;
	}
	return (1);
}

int	alloc_lst_test_ldoulbes(t_lst_test *tests)
{
	int	i;

	tests->ldoubles = (t_ld *)malloc(MAX_LST_NODES_NUM * sizeof (t_ld));
	if (tests->ldoubles == NULL)
		return (0);
	tests->ldbls_ptrs = (t_ld **)malloc(MAX_LST_NODES_NUM * sizeof (t_ld *));
	if (tests->ldbls_ptrs == NULL)
	{
		free(tests->ldoubles);
		return (0);
	}
	i = 0;
	while (i < MAX_LST_NODES_NUM)
	{
		tests->ldbls_ptrs[i] = NULL;
		i++;
	}
	return (1);
}

int	alloc_lst_test_strings(t_lst_test *tests)
{
	if (!alloc_lst_test_strs(tests))
		return (0);
	if (!alloc_lst_test_strs_ptrs(tests))
		return (0);
	return (1);
}

int	alloc_lst_test_strs(t_lst_test *tests)
{
	int	i;

	tests->strs = (char **)malloc(MAX_LST_NODES_NUM * sizeof (char *));
	if (tests->strs == NULL)
		return (0);
	i = 0;
	while (i < MAX_LST_NODES_NUM)
	{
		tests->strs[i] = (char *)malloc(MAX_TEST_STR_LEN * sizeof (char));
		if (tests->strs[i] == NULL)
		{
			i--;
			while (i >= 0)
			{
				free(tests->strs[i]);
				i--;
			}
			free(tests->strs);
			return (0);
		}
		i++;
	}
	return (1);
}
