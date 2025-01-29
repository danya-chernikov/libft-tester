#include "../include/list.h"

int	alloc_lst_test_floats(t_lst_test *tests)
{
	float	**floats_ptrs;
	float	*floats;
	int		i;

	floats = (float *)malloc(MAX_LST_NODES_NUM * sizeof (float));
	if (floats == NULL)
		return (ERROR);
	tests->floats = floats;
	floats_ptrs = (float **)malloc(MAX_LST_NODES_NUM * sizeof (float *));
	if (floats_ptrs == NULL)
	{
		free(tests->floats);
		return (ERROR);
	}
	tests->floats_ptrs = floats_ptrs;
	i = 0;
	while (i < MAX_LST_NODES_NUM)
	{
		tests->floats_ptrs[i] = NULL;
		i++;
	}
	return (SUCCESS);
}

int	alloc_lst_test_doubles(t_lst_test *tests)
{
	double	**dbls_ptrs;
	double	*doubles;
	int		i;

	doubles = (double *)malloc(MAX_LST_NODES_NUM * sizeof (double));
	if (doubles == NULL)
		return (ERROR);
	tests->doubles = doubles;
	dbls_ptrs = (double **)malloc(MAX_LST_NODES_NUM * sizeof (double *));
	if (dbls_ptrs == NULL)
	{
		free(tests->doubles);
		return (ERROR);
	}
	tests->dbls_ptrs = dbls_ptrs;
	i = 0;
	while (i < MAX_LST_NODES_NUM)
	{
		tests->dbls_ptrs[i] = NULL;
		i++;
	}
	return (SUCCESS);
}

int	alloc_lst_test_ldoubles(t_lst_test *tests)
{
	t_ld	**ldbls_ptrs;
	t_ld	*ldoubles;
	int		i;

	ldoubles = (t_ld *)malloc(MAX_LST_NODES_NUM * sizeof (t_ld));
	if (ldoubles == NULL)
		return (ERROR);
	tests->ldoubles = ldoubles;
	ldbls_ptrs = (t_ld **)malloc(MAX_LST_NODES_NUM * sizeof (t_ld *));
	if (ldbls_ptrs == NULL)
	{
		free(tests->ldoubles);
		return (ERROR);
	}
	tests->ldbls_ptrs = ldbls_ptrs;
	i = 0;
	while (i < MAX_LST_NODES_NUM)
	{
		tests->ldbls_ptrs[i] = NULL;
		i++;
	}
	return (SUCCESS);
}

int	alloc_lst_test_strings(t_lst_test *tests)
{
	if (!alloc_lst_test_strs(tests))
		return (ERROR);
	if (!alloc_lst_test_strs_ptrs(tests))
		return (ERROR);
	return (SUCCESS);
}

int	alloc_lst_test_strs(t_lst_test *tests)
{
	char	**strs;
	int		i;

	strs = (char **)malloc(MAX_LST_NODES_NUM * sizeof (char *));
	if (strs == NULL)
		return (ERROR);
	tests->strs = strs;
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
			return (ERROR);
		}
		i++;
	}
	return (SUCCESS);
}
